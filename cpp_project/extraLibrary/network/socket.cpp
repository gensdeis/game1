#include "stdafx_net.h"
#include "define.h"

#include "network.h"
#include "session.h"
#include "sessionPool.h"
#include "socket.h"
#include "server.h"
#include "packetContextPool.h"
#include "networkConfig.h"
#include <common/config.h>

#include <protocol/mp_session_certify.h>
#include <protocol/mp_session_open.h>
#include <protocol/mp_heartbeat_check.h>
#include <protocol/mrpc_connector_rpcinfo.h>
#include <protocol/mp_auth_check.h>
#include <protocol/mp_session_auth.h>
#include <protocol/mp_session_type.h>
#include <protocol/mp_error_message.h>
#include <protocol/mrpc_heartbeat_check.h>
#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
#include <network/networkController.h>
#include <protocol/mrpc_player_connect_info.h>
#include <protocol/mrpc_game_duplicate_login.h>
#endif
#ifdef _WINDOWS
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <mstcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#endif

#include <protocol/base_protocol_enumstring.h>

namespace mir3d
{
	CSocket::CSocket(boost::asio::io_service& io_service, int32_t socket_id, CServer* server) : _io_service(io_service), _socket_id(socket_id), _server(server), _heartbeat_deadline_timer(io_service)
#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN  		
																																															, _duplication_login_force_close_timer(io_service)
#endif
	{
		for (int32_t i = 0; i < 2; i++)
		{
			{			
				auto temp = new List_Write_Buffer();
				temp->reserve(32);
				_list_write_buffer.push_back(temp);
			}
		}

#ifdef _USE_NEW_NOT_ALLOW_PACKET		
		// uint8_t* _packet_receive_count = null;
#ifdef _USE_PACKET_COUNT
		_packet_receive_count = new int32_t[static_cast<int32_t>(mpe_cmd::cmd_max)];
		memset(_packet_receive_count, 0x00, sizeof(int32_t) * static_cast<int32_t>(mpe_cmd::cmd_max));
#endif
#else
		_not_allow_packet[0].cmd = mir3d::mpe_cmd::zone_client_request_object_info_cs;
		_not_allow_packet[0].receive_time = 0;
		_not_allow_packet[0].limit_time = 1000;

		_not_allow_packet[1].cmd = mir3d::mpe_cmd::illusion_dungeon_time_out_cs;
		_not_allow_packet[1].receive_time = 0;
		_not_allow_packet[1].limit_time = 50000;
#endif

		_heartbeat_cs_packet_buffer = Network::GetHeartbeatPacket();

		// packet check time
		if (true == NetworkConfig::GetHeartbeat_Check())
		{
			_check_packet_time = NetworkConfig::GetHeartbeat_CheckTime() * 1000;
		}
	}

	CSocket::~CSocket()
	{
		Destroy();
	}

	bool CSocket::Initialize(void)
	{
		if (nullptr != _socket)
		{
			SAFE_DELETE(_socket);
		}

		_socket = new boost::asio::ip::tcp::socket(_io_service);

		_force_disconnect = false;

		_write_use_count.exchange(0);
		_heartbeat_check_count.exchange(0);

		for (auto item : _list_write_buffer)
			item->clear();

		_list_write_buffer_seq.clear();

		if (ULONG_MAX <= _token_id)
			_token_id = 0;

		_token_id++;

		_Seed = mir3d::util::mirRandom.Get(1, 100000);

		_socket_rpc_fulltag.clear();
		_socket_remote_info.clear();
		_socket_remote_ip.clear();

		return true;
	}

#ifdef _USE_NEW_NOT_ALLOW_PACKET
	void CSocket::InitializeNotAllowPacket(void)
	{
		if (nullptr != _server)
		{
			_server->UpdateNotAllowPacket(_list_not_allow_packet);
			_list_not_allow_packet_index++;
		}
	}
#endif

	void CSocket::SetConnecter(void)
	{
		_connecter = true;

		setSocketOption(true);
	}
	   
	bool CSocket::SetSession(const int64_t& auid, const int64_t& cuid, const int64_t& session_id, const std::string& uuid)
	{
		bool reconnect_session = false;

		auto received_session_id = session_id;
		auto received_session_uuid = uuid;

		// 2023.07.31 gogoblue74 gate 에 재연결시 처리를 위해
		// gate에서 기존 연결 처리를 위해 game 서버에 물어봐야한다.
		if (mir3d::mrpce_server_type::gate == mir3d::GameConfig::Server_Type())
		{
			received_session_id = 0;
			received_session_uuid = "";
		}

		if (false == IsRpc() && 0 < received_session_id)
		{
			//카운트 횟수를 넘긴 클라는 튕겨낸다. 10은 클라에 정의된 max retry 수치임
			if (3 <= _reconnect_try_count)// if (10 <= _reconnect_try_count)	// gogoblue74 2022.07.14
			{
				SERVER_LOG(eServerLogType::eDebug, "force disconnect, session reconnect session retry count : %d, session id : %lld", _reconnect_try_count, received_session_id);
				ForceDisconnect("CSocket::SetSession(0)", true);
				return false;
			}

			_session = SessionPool::PopWait(received_session_id);

			if (nullptr != _session)
			{
				reconnect_session = true;
			}
			else
			{
				auto session = _server->GetSession(received_session_id);

				if (nullptr != session)
				{
					if (false == session->CertifyUuid(received_session_uuid))
					{
						SERVER_LOG(eServerLogType::eDebug, "session_id : %lld, uuid is differnt, session uuid : %s  != %s", received_session_id, session->GetUuid().c_str(), received_session_uuid.c_str());
						return false;
					}

					//기존 소켓 해제
					auto socket = session->GetSocket();
					if (nullptr != socket)
					{
						socket->ForceDisconnect("CSocket::SetSession(1)", true);

						_reconnect_try_count++;

						if (NetworkConfig::GetReconnectTryCount() <= _reconnect_try_count)
						{
							_reconnect_try_count = 10;
						}

						mir3d::mp_session_open_sc packet;
						packet.result = mpe_error::session_timeout;
						packet.session_id = _reconnect_try_count;

						auto data = std::make_shared<CSocketWriteBuffer>();
						if (data->buffer)
						{
							protocol::SerializeType(data->buffer, &packet);
							PostWrite(data);
						}

						SERVER_LOG(eServerLogType::eDebug, "CSocket::SetSession(1) mp_session_open_sc result : %d, auid : %lld", static_cast<int32_t>(packet.result), auid);
						return true;
					}
					
					_session = session;
					reconnect_session = true;
				}
				else if (false == IsConnecter())
				{
					_reconnect_try_count++;

					mir3d::mp_session_open_sc packet;
					packet.result = mpe_error::session_timeout;
					packet.session_id = _reconnect_try_count;

					auto data = std::make_shared<CSocketWriteBuffer>();
					if (data->buffer)
					{
						protocol::SerializeType(data->buffer, &packet);
						PostWrite(data);
					}

					SERVER_LOG(eServerLogType::eDebug, "CSocket::SetSession(2) mp_session_open_sc result : %d, auid : %lld", static_cast<int32_t>(packet.result), auid);

					return true;
				}
			}

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN  		
			if (_session->IsDuplicationLoginForceClose())
			{
				SERVER_LOG(eServerLogType::eDebug, "_session->IsDuplicationLoginForceClose() is true, retry count : %d, session id : %lld", _reconnect_try_count, session_id);
				return false;
			}
#endif
		}
		else
		{
			_session = SessionPool::Pop();
		}

		if (nullptr != _session)
		{
#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
			bool reconnect = false;
			if (false == IsRpc() && 0 < received_session_id && 0 < received_session_uuid.length())
			{
				reconnect = true;
			}

			if (false == IsRpc() && false == session_auth_process(_session, auid, cuid, reconnect))
			{

				mir3d::mp_session_open_sc packet;
				packet.result = mpe_error::session_timeout;
				packet.session_id = _reconnect_try_count;

				auto data = std::make_shared<CSocketWriteBuffer>();
				if (data->buffer)
				{
					protocol::SerializeType(data->buffer, &packet);
					PostWrite(data);
				}

				SERVER_LOG(eServerLogType::eDebug, "CSocket::SetSession(3) mp_session_open_sc result : %d, auid : %lld", static_cast<int32_t>(packet.result), auid);

				// 2023.07.21 gogoblue74 
				// 여기에서 리턴을 하면 소켓이 ghost로 처리되지 않아 연결 상태로 남아 버린다.
				_session = nullptr;

				return true;
			}
#endif
			bool reconnect_gate_session = false;
			if (mir3d::mrpce_server_type::gate == mir3d::GameConfig::Server_Type())
			{
				if (0 < session_id && 0 < uuid.length())
				{
					reconnect_gate_session = true;
				}
			}

			_session->Initialize(received_session_id, this, reconnect_session, reconnect_gate_session);
			_server->SetSession(_session);

			SetRemoteInfo();

			return true;
		}
		
		return false;
	}

	void CSocket::setSocketOption(bool openflag)
	{
		if (openflag)
		{
			boost::system::error_code error_code;
			_socket->open(boost::asio::ip::tcp::v4(), error_code);
			if (error_code)
			{
				SERVER_LOG(eServerLogType::eWarning, "error No: %d, error Message: %s", error_code.value(), error_code.message().c_str());
			}
		}

		// no_delay
		{
			boost::system::error_code error_code;
			boost::asio::ip::tcp::no_delay option(true);
			_socket->set_option(option, error_code);
			if (error_code)
			{
				SERVER_LOG(eServerLogType::eWarning, "error No: %d, error Message: %s", error_code.value(), error_code.message().c_str());
			}
		}

		int32_t socket_buffer_size = 16384;
		
		if (IsRpc())
			socket_buffer_size = 65536;

		// send_buffer_size
		{
			boost::system::error_code error_code;
			boost::asio::socket_base::send_buffer_size option(socket_buffer_size);
			_socket->set_option(option, error_code);
			if (error_code)
			{
				SERVER_LOG(eServerLogType::eWarning, "error No: %d, error Message: %s", error_code.value(), error_code.message().c_str());
			}
		}
		// receive_buffer_size
		{
			boost::system::error_code error_code;
			boost::asio::socket_base::receive_buffer_size option(socket_buffer_size);
			_socket->set_option(option, error_code);
			if (error_code)
			{
				SERVER_LOG(eServerLogType::eWarning, "error No: %d, error Message: %s", error_code.value(), error_code.message().c_str());
			}
		}
		// keep_alive
		{
#ifdef _DELETE		// 2023.02.11 keep alive 안함, gogoblue74

#ifdef _WINDOWS
			if (IsRpc())
			{

				DWORD dwBytes = 0;
				tcp_keepalive keep_option = { 0 };
				keep_option.onoff = 1;
				keep_option.keepalivetime = 1000;		// 1초 마다 keep alive 신호를 보낸다.
				keep_option.keepaliveinterval = 1000;	// keep alive 신호를 보내고 응답 없으면 1초마다 재 전송, (ms tcp는 10회 재시도)

				auto error_code = WSAIoctl(_socket->native_handle(), SIO_KEEPALIVE_VALS, &keep_option, sizeof(keep_option), 0, 0, &dwBytes, NULL, NULL);
				if (0 != error_code)
				{
					SERVER_LOG(eServerLogType::eWarning, "CSocket::setSocketOption() setsockopt():so_keepalive failed. %d", error_code);
				}
			}
#else
			int32_t result;

			int32_t keepAliveSet = 1;
			int32_t keepAliveIdle = 1;
			int32_t keepAliveCount = 5;
			int32_t keepAliveInterval = 1;

			result = setsockopt(_socket->native_handle(), SOL_SOCKET, SO_KEEPALIVE, &keepAliveSet, sizeof(int32_t));
			if (-1 == result)
			{
				SERVER_LOG(eServerLogType::eDebug, "CSocket::setSocketOption() setsockopt():so_keepalive failed.";
				return;
			}

			result = setsockopt(_socket->native_handle(), SOL_TCP, TCP_KEEPIDLE, &keepAliveIdle, sizeof(int32_t));
			if (-1 == result)
			{
				SERVER_LOG(eServerLogType::eDebug, "CSocket::setSocketOption() setsockopt():so_keepidle failed.";
				return;
			}

			result = setsockopt(_socket->native_handle(), SOL_TCP, TCP_KEEPCNT, &keepAliveCount, sizeof(int32_t));
			if (-1 == result)
			{
				SERVER_LOG(eServerLogType::eDebug, "CSocket::setSocketOption() so_keepcnt():so_keepidle failed.";
				return;
			}

			result = setsockopt(_socket->native_handle(), SOL_TCP, TCP_KEEPINTVL, &keepAliveInterval, sizeof(int32_t));
			if (-1 == result)
			{
				SERVER_LOG(eServerLogType::eDebug, "CSocket::setSocketOption() so_keepintvl():so_keepidle failed.";
				return;
			}
#endif	// _WINDOWS

#endif // _DELETE
		}
		// linger
		{
			boost::system::error_code error_code;
			boost::asio::socket_base::linger option(true, 0);	//  hard or abortive shutdown
			_socket->set_option(option, error_code);
			if (error_code)
			{
				SERVER_LOG(eServerLogType::eWarning, "error No: %d, error Message: %s", error_code.value(), error_code.message().c_str());
			}
		}
	}

	void CSocket::Release()
	{
		if (_socket != nullptr)
		{
			SERVER_LOG(eServerLogType::eDebug, "CSocket::Release() %s, connect state : %d, is_open : %d", GetRemoteInfo().c_str(), ConnectState(), _socket->is_open());
		}
		else
		{
			SERVER_LOG(eServerLogType::eDebug, "CSocket::Release() %s, connect state : %d", GetRemoteInfo().c_str(), ConnectState());
		}

		SetConnectedState(eSocketState::none);
		
		if (nullptr != _session)
		{
			if (false == _disposal_close_socket)
			{
				if (mrpce_server_type::gate == GameConfig::Server_Type() || mrpce_server_type::community == GameConfig::Server_Type() || mrpce_server_type::world_community == GameConfig::Server_Type())
				{
					_session->Destroy();
					SessionPool::Push(_session);
				}
				else if (IsRpc() || IsConnecter() || _session->IsRedirection())
				{
					_session->Destroy();
					SessionPool::Push(_session);
				}
				else
				{
					SessionPool::PushWait(_session);
				}
			}
			
			_session = nullptr;
		}

		_connecter = false;
		_rpc = false;
		_reconnect_try_count = 0;

		for (auto item : _list_write_buffer)
			item->clear();
		
		_list_write_buffer_seq.clear();

		if (nullptr != _socket_read_buffer)
		{
			if (IsRpc())
				SocketReadBufferPool::PushRpc(_socket_read_buffer);
			else
				SocketReadBufferPool::Push(_socket_read_buffer);

			_socket_read_buffer = nullptr;
		}

		if (nullptr != _read_buffer)
		{
			if (IsRpc())
				ReadBufferPool::PushRpc(_read_buffer);
			else
				ReadBufferPool::Push(_read_buffer);

			_read_buffer = nullptr;
		}

		_Seed = 0;
		_Crypt.ReleaseCrypt();

		_speed_hack_count = 0;
		_speed_hack_check_time = 0;

		_write_use_time = 0;

#ifdef _USE_PACKET_COUNT
		memset(_packet_receive_count, 0x00, sizeof(int32_t) * static_cast<int32_t>(mpe_cmd::cmd_max));
#endif

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN  

		if (false == IsRpc())
		{
			if (mrpce_server_type::gate == GameConfig::Server_Type() || mrpce_server_type::community == GameConfig::Server_Type() || mrpce_server_type::world_community == GameConfig::Server_Type())
			{
				networkController.DisconnectSocket(__func__, _socket_client_auid, false, true, 0);
			}
			else if (0 < _socket_client_auid)
			{
				networkController.DisconnectSocket(__func__, _socket_client_auid, false, false, _socket_access_token);
			}
		}

		_socket_access_token = 0;
		
		SetCompletedAuthentication(false);
#endif

		_socket_client_auid = 0;

		_disposal_close_socket = false;
		_mpay_socket_session = false;

		SetSocketConnectedTime(true);
	}

	void CSocket::Destroy()
	{
		if (nullptr != _socket_read_buffer)
		{
			if (IsRpc())
				SocketReadBufferPool::PushRpc(_socket_read_buffer);
			else
				SocketReadBufferPool::Push(_socket_read_buffer);
			
			_socket_read_buffer = nullptr;
		}

		if (nullptr != _read_buffer)
		{
			if (IsRpc())
				ReadBufferPool::PushRpc(_read_buffer);
			else
				ReadBufferPool::Push(_read_buffer);
			
			_read_buffer = nullptr;
		}
	}

	void CSocket::Connected(void)
	{
		SetConnectedState(eSocketState::connected);
		
		if (nullptr != _server)
		{
			_server->SocketOpened(this);
		}

		if (nullptr == _socket_read_buffer)
		{
			if (IsRpc())
				_socket_read_buffer = SocketReadBufferPool::PopRpc();
			else
				_socket_read_buffer = SocketReadBufferPool::Pop();
		}
		else
		{
			SERVER_LOG(eServerLogType::eWarning, "CSocket::Connected() what??????? _socket_read_buffer is not null");
		}

		if (nullptr == _read_buffer)
		{
			if (IsRpc())
				_read_buffer = ReadBufferPool::PopRpc();
			else
				_read_buffer = ReadBufferPool::Pop();
		}
		else
		{
			SERVER_LOG(eServerLogType::eWarning, "CSocket::Connected() what??????? _read_buffer is not null");
		}	

		if (nullptr == _read_buffer || nullptr == _socket_read_buffer)
		{
			SERVER_LOG(eServerLogType::eWarning, "_read_buffer _socket_read_buffer is null");
		}

		setSocketOption();

		if (IsConnecter())
		{
			mp_session_certify_cs message;
			message.session_id = 0;

			auto data = std::make_shared<CSocketWriteBuffer>();
			if (data->buffer)
			{
				protocol::SerializeType(data->buffer, &message);

				PostWrite(data);
			}
		}
#ifdef _USE_SERVER_SEVICE_TIME
		else if (IsRpc())
		{
			mrpc_connector_rpcinfo_cs message;

			auto data = std::make_shared<CSocketWriteBuffer>();
			if (data->buffer)
			{
				protocol::SerializeType(data->buffer, &message);

				PostWrite(data);
			}
		}
#endif

		SetRemoteInfo();
		SetRemoteIp();

		SetSocketConnectedTime(false);
	}

	void CSocket::ForceDisconnect(const char* call_func, const bool& post_close_socket, const bool& duplication_close_socket)
	{
// #ifdef _DEBUG
		SERVER_LOG(eServerLogType::eDebug, "CSocket::ForceDisconnect() call func : %s, PostClose() : %d, duplication : %d, %s", call_func, post_close_socket, duplication_close_socket, GetRemoteInfo().c_str());
// #endif

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN  
		if (duplication_close_socket)
		{
			auto sesstion = GetSession();

			if (nullptr != sesstion)
			{
				sesstion->SetDuplicationLoginForceClose();
			}
		}
#endif

		SetForceDisconnect();

		if (post_close_socket)
		{
			PostClose(call_func);
		}
	}

	void CSocket::SetRemoteInfo(void)
	{
		if (eSocketState::connected == ConnectState())
		{
			auto addr = _socket->remote_endpoint();
			int64_t session_id = nullptr != GetSession() ? GetSession()->GetID() : -1;

			std::stringstream stream;

			if (IsRpc())
			{
				stream << addr.address().to_string() << ":" << std::to_string(addr.port()) << ", [" << _socket_rpc_fulltag << "], [socket id : " << GetID() << "], [sesseion id : " << session_id << "]";				
			}
			else
			{
				stream << addr.address().to_string() << ":" << std::to_string(addr.port()) << ", auid : " << _socket_client_auid << ", [socket id : " << GetID() << "], [sesseion id : " << session_id << "]";
			}

			_socket_remote_info = stream.str();
		}
	}

	void CSocket::PostClose(const char* call_func)
	{
		SERVER_LOG(eServerLogType::eDebug, "CSocket::PostClose() call function : %s, ConnectState() : %d, socket id : %d, auid : %lld, %s", call_func, ConnectState(), GetID(), _socket_client_auid, GetRemoteInfo().c_str());

		// 2023.08.26 gogoblue74 무조건 close 처리 시도한다.
		// if (CSocket::eSocketState::connected == ConnectState())
		{
			SetConnectedState(eSocketState::close);

			_io_service.post(boost::bind(&CSocket::implement_close, this));
		}
	}

	void CSocket::implement_close(void)
	{
		try
		{
			if (eSocketState::connected != ConnectState())
			{
				SetConnectedState(eSocketState::disconnect);

				if (nullptr != _socket)
				{
					if (_socket->is_open())
					{
						boost::system::error_code ignored_ec;
						_socket->shutdown(boost::asio::socket_base::shutdown_type::shutdown_both, ignored_ec);
						_socket->close();
					}

					//#ifdef _DEBUG
					//				SAFE_DELETE(_socket);
					//#endif
				}

				if (false == _disposal_close_socket)
				{
					_server->DisconnectedSocket(_socket_id);
				}

				Release();
			}
			else
			{
				SERVER_LOG(eServerLogType::eWarning, "CSocket::close() ConnectState() is eSocketState::connected. socket id : %d", GetID());
			}

		}
		catch (std::exception& e)
		{
			SERVER_LOG(eServerLogType::eWarning, "CSocket::close() exception %s", e.what());
		}
	}

	void CSocket::PostReceive(void)
	{
		if (CSocket::eSocketState::connected == ConnectState())
		{
			_io_service.post(boost::bind(&CSocket::implement_receive, this));
		}
	}

	void CSocket::implement_receive(void)
	{
		if (CSocket::eSocketState::connected == ConnectState() && nullptr != _read_buffer)
		{
			_read_buffer->reset();

			_socket->async_read_some(boost::asio::buffer(_read_buffer->buffer, _read_buffer->size()),
							boost::bind(&CSocket::callback_receive, this, _read_buffer, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
		}
	}

	void CSocket::callback_receive(read_buffer* buffer, const boost::system::error_code& error_code, size_t bytes_transferred)
	{
		if (error_code)
		{
			if (GetForceDisconnect())
			{
				SERVER_LOG(eServerLogType::eWarning, "CSocket::callback_receive(_force_disconnect) %s, error No: %d, error Message: %s", GetRemoteInfo().c_str(), error_code.value(), error_code.message().c_str());
			}
			else if (CSocket::eSocketState::connected == ConnectState())
			{
				SERVER_LOG(eServerLogType::eWarning, "CSocket::callback_receive() %s, error No: %d, %s", GetRemoteInfo().c_str(), error_code.value(), error_code.message().c_str());
			}
			else
			{
				SERVER_LOG(eServerLogType::eWarning, "CSocket::callback_receive() %s, what???", GetRemoteInfo().c_str());
			}

			PostClose("CSocket::callback_receive(0)");
		}
		else if (GetForceDisconnect())
		{
			SERVER_LOG(eServerLogType::eDebug, "CSocket::callback_receive() _force_disconnect is true, %s", GetRemoteInfo().c_str());
			PostClose("CSocket::callback_receive(1)");
		}
		else
		{	

			if (0 == bytes_transferred || bytes_transferred > static_cast<size_t>(buffer->size()))
			{
				SERVER_LOG(eServerLogType::eWarning, "CSocket::callback_receive() %s, size over : %d", GetRemoteInfo().c_str(), bytes_transferred);
				ForceDisconnect(__func__, true);
				return;
			}

			buffer->set_size(bytes_transferred);

			_curr_token_id = _token_id;

			receive(buffer);

			implement_receive();
		}
	}

	void CSocket::receive(read_buffer* buffer)
	{
		if (CSocket::eSocketState::connected != ConnectState())
		{
			return;
		}

		if (nullptr == _socket_read_buffer)
		{
			SERVER_LOG(eServerLogType::eWarning, "CSocket::receive() - _socket_read_buffer is null !!!");
			ForceDisconnect("CSocket::receive(0)", true);
			return;
		}

		bool result = _socket_read_buffer->PushRecvComplete((uint8_t*)buffer->buffer, buffer->size());
		if (false == result)
		{
			ForceDisconnect("CSocket::receive(1)", true);
			return;
		}

		uint8_t*		temp_packet = nullptr;
		int32_t			receive_packet_size = 0;
#ifdef _USE_NEW_PACKET_HEADER		
		int32_t			receive_client_time = 0;
#endif
		mpe_cmd			receive_command = mpe_cmd::none;
		mpe_rpc_cmd		receive_rpc_command = mpe_rpc_cmd::none;
		bool			force_close_socket = false;
			
		while (true)
		{
			if (_socket_read_buffer->GetDataSize() == 0)
			{
				break;	// 0일때 handle_header_receive() 타면 버퍼 망가진다.
			}

#ifdef _USE_NEW_PACKET_ENCRYPTION
			receive_packet_size = _socket_read_buffer->GetPacket(force_close_socket, temp_packet);

			if (force_close_socket)
			{
				ForceDisconnect(true);
				break;
			}
#else

			if (true == GameConfig::Server_Encryption() && false == IsRpc())
			{
				handle_header_receive();
			}
						
			receive_packet_size = _socket_read_buffer->GetPacket(force_close_socket, temp_packet);

			if (force_close_socket)
			{
				SERVER_LOG(eServerLogType::eWarning, "CSocket::receive() force_close_socket, %s", GetRemoteInfo().c_str());
				ForceDisconnect("CSocket::receive(2)", true);
				break;
			}
#endif		// _USE_NEW_PACKET_ENCRYPTION

			if (0 < receive_packet_size && nullptr != temp_packet)
			{
				memcpy(&receive_command, &temp_packet[PACKET_LENGTH_SIZE], PACKET_COMMAND_SIZE);

#ifdef _USE_NEW_PACKET_HEADER
				if (false == IsRpc())
				{
					memcpy(&receive_client_time, &temp_packet[PACKET_CLIENT_TIME_POS], PACKET_CLIENT_TIME_SIZE);
					// SERVER_LOG(eServerLogType::eInfo, "client time : %d", receive_client_time);
				}
#endif

				receive_rpc_command = static_cast<mpe_rpc_cmd>(receive_command);

#ifdef _USE_NEW_PACKET_ENCRYPTION
				if (true == GameConfig::Server_Encryption() && mrpce_server_type::aiservice != GameConfig::Server_Type() && false == IsRpc())
				{
					decryption_receive_buffer(receive_packet_size - PACKET_HEADER_SIZE, &temp_packet[PACKET_HEADER_SIZE]);
				}
#endif			

				if (false == IsRpc())
				{
					if (false == receive_header_check(temp_packet))
					{
						SendErrorMessage(mpe_error::unknown_packet);
						ForceDisconnect("CSocket::receive(3)", true);
						break;
					}

					if (mir3d::mpe_cmd::heartbeat_check_cs == receive_command)
					{
						auto packet_buffer = std::make_shared<CSocketWriteBuffer>();
						if (packet_buffer->buffer)
						{
							mp_heartbeat_check_sc packet;
							packet.temp = 0;
							protocol::SerializeType(packet_buffer->buffer, &packet);

							PostWrite(packet_buffer);
						}

						// packet check time
						if (true == NetworkConfig::GetHeartbeat_Check())
						{
							SetLastPacketTime();
						}

						continue;
					}
					else if (mir3d::mpe_cmd::heartbeat_check_sc == receive_command)
					{
						_heartbeat_check_count.exchange(0);
						continue;
					}

					if (nullptr == _session)
					{
						//client
						if (mir3d::mpe_cmd::auth_check_cs == receive_command)
						{
							SendAuthServerSeed();
							continue;
						}
						else if (mir3d::mpe_cmd::session_auth_cs == receive_command)
						{
							mir3d::mp_session_auth_cs cs;
							if (mir3d::protocol::UnSerializeNative((uint8_t*)&temp_packet[PACKET_HEADER_SIZE], receive_packet_size - PACKET_HEADER_SIZE, &cs))
							{
								auto received_auid = cs.auid;

								cs.auid = 0;

								if (handle_auth_session(cs.auid, cs.client_seed, cs.digest) == -1)
								{
									SERVER_LOG(eServerLogType::eWarning, "CSocket::receive() handle_auth_session error auid : %lld, session_id : %lld", cs.auid, cs.session_id);
									break;
								}

								if (false == SetSession(received_auid, cs.cuid, cs.session_id, cs.session_uuid))
								{
									// 3회 이상 시도 또는 삭제 완료 된 session
									ForceDisconnect("CSocket::receive(4)", true);
									SERVER_LOG(eServerLogType::eWarning, "SetSession() is false.");
									return;
								}

								if (nullptr != _session)
								{
									init_auth_crypt();
								}
							}

							continue;
						}
					}
				}
				else
				{
					if (mir3d::mpe_rpc_cmd::connector_rpcinfo_cs == receive_rpc_command)
					{
						auto packet_buffer = std::make_shared<CSocketWriteBuffer>();
						if (packet_buffer->buffer)
						{
							mrpc_connector_rpcinfo_sc sc;
							sc.name = NetworkConfig::GetServerName();							
							sc.gid = GameConfig::Server_Gid();
							sc.type = GameConfig::Server_Type();
							sc.index = GameConfig::Server_Index();
							protocol::SerializeType(packet_buffer->buffer, &sc);
							PostWrite(packet_buffer);
						}

						continue;
					}
					else if (mir3d::mpe_rpc_cmd::heartbeat_check_cs == receive_rpc_command)
					{
						mir3d::mrpc_heartbeat_check_cs cs;
						if (mir3d::protocol::UnSerializeNative((uint8_t*)&temp_packet[PACKET_HEADER_SIZE], receive_packet_size - PACKET_HEADER_SIZE, &cs))
						{
							auto packet_buffer = std::make_shared<CSocketWriteBuffer>();
							if (packet_buffer->buffer)
							{
								mrpc_heartbeat_check_sc sc;
								sc.uid = cs.uid;
								sc.param = cs.param;
								protocol::SerializeType(packet_buffer->buffer, &sc);
								PostWrite(packet_buffer);
							}
						}						
						continue;
					}
#ifdef	_USE_NOT_ALLOW_DUPLICATION_LOGIN
					// lobby -> gm server -> gm observer -> games broardcast
					else if (mir3d::mpe_rpc_cmd::player_connect_info_cs == receive_rpc_command)
					{
						if (NetworkConfig::GetUseNotAllowDuplicationLogin())
						{
							mir3d::mrpc_player_connect_info_cs cs;
							if (mir3d::protocol::UnSerializeNative((uint8_t*)&temp_packet[PACKET_HEADER_SIZE], receive_packet_size - PACKET_HEADER_SIZE, &cs))
							{
#ifdef _DEBUG									
								SERVER_LOG(eServerLogType::eDebug, "mrpc_player_connect_info_cs() received. from : %s, access_token : %lld, auid : %lld, cuid : %lld", GetRemoteInfo().c_str(), cs.access_token, cs.auid, cs.cuid);
#endif
								if (0 == cs.flag)			// 해당 서버
								{
									//  auid를 key 찾아 봐서 기존 socket이 있으면  force close 시킨다.
									networkController.SetConnectionWait(__func__, cs.access_token, cs.gid, cs.auid, cs.cuid, false);
								}
								else if (1 == cs.flag)		// 다른 서버
								{
									networkController.DisconnectSocket(__func__, cs.auid, true, false, 0);
								}
							}
						}

						continue;
					}
					// game / indun / world game / world indun -> broadcast (games)
					else if (mir3d::mpe_rpc_cmd::player_connect_info_sc == receive_rpc_command)
					{
						if (NetworkConfig::GetUseNotAllowDuplicationLogin())
						{
							if (!(mir3d::mrpce_server_type::gate == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_community == mir3d::GameConfig::Server_Type()))
							{
								mir3d::mrpc_player_connect_info_sc sc;
								if (mir3d::protocol::UnSerializeNative((uint8_t*)&temp_packet[PACKET_HEADER_SIZE], receive_packet_size - PACKET_HEADER_SIZE, &sc))
								{
#ifdef _DEBUG									
									SERVER_LOG(eServerLogType::eDebug, "mrpc_player_connect_info_sc() received. from : %s, access_token : %lld, auid : %lld, cuid : %lld, flag : %d", GetRemoteInfo().c_str(), sc.access_token, sc.auid, sc.cuid, sc.flag);
#endif

									networkController.DisconnectSocket(__func__, sc.auid, true, false, 0);
								}
							}
						}

						continue;
					}
					else if (mir3d::mpe_rpc_cmd::game_duplicate_login_sc == receive_rpc_command)
					{
						if (NetworkConfig::GetUseNotAllowDuplicationLogin())
						{
							if (!(mir3d::mrpce_server_type::gate == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_community == mir3d::GameConfig::Server_Type()))
							{
								mir3d::mrpc_game_duplicate_login_sc sc;
								if (mir3d::protocol::UnSerializeNative((uint8_t*)&temp_packet[PACKET_HEADER_SIZE], receive_packet_size - PACKET_HEADER_SIZE, &sc))
								{
#ifdef _DEBUG
									SERVER_LOG(eServerLogType::eDebug, "mrpc_game_duplicate_login_sc() received. auid : %lld, access token : %lld, type : %d", sc.auid, sc.access_token, sc.type);
#endif						
									
									networkController.DisconnectSocket(__func__, sc.auid, true, false, 0);				

								}
							}
						}

						continue;
					}
#endif
				}
								
				if (nullptr == _session)
				{					// dummy
					if (mir3d::mpe_cmd::session_type_cs == receive_command)
					{
						mir3d::mp_session_type_cs cs;
						if (mir3d::protocol::UnSerializeNative((uint8_t*)&temp_packet[PACKET_HEADER_SIZE], receive_packet_size - PACKET_HEADER_SIZE, &cs))
						{
							if (true == cs.is_dummy)
							{
								SetDummy(true);
								SetSession(cs.auid, 0, 0, "");
							}

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
							else {
								if (NetworkConfig::GetUseNotAllowDuplicationLogin())
								{
									if (false == networkController.SetSocket(cs.auid, this, _socket_access_token))
									{
										ForceDisconnect("CSocket::receive(5)", true);
										break;
									}
								}
							}

							SetCompletedAuthentication(true);
#endif
						}
					}
					// rpc
					else if (mir3d::mpe_cmd::session_certify_cs == receive_command && (IsRpc() || IsDummy()))
					{
						mir3d::mp_session_certify_cs packet;
						if (mir3d::protocol::UnSerializeNative((uint8_t*)&temp_packet[PACKET_HEADER_SIZE], receive_packet_size - PACKET_HEADER_SIZE, &packet))
						{
							if (false == SetSession(0, 0, packet.session_id, ""))
							{
								ForceDisconnect("CSocket::receive(6)", true);
								return;
							}
						}
					}
					// connector 가 받은거 / rpc, dummy 가 server가 보낸거 받은 경우
					else if (mir3d::mpe_cmd::session_open_sc == receive_command)
					{
						SetDummy(true);
						if (false == SetSession(0, 0, 0, ""))
						{
							ForceDisconnect("CSocket::receive(7)", true);
							return;
						}
					}
					else
					{
						SERVER_LOG(eServerLogType::eWarning, "CSocket::callback_receive() - drop packet, cmd : %d, %s", receive_command, GetRemoteInfo().c_str());
					}
				}
				else
				{
					if (CSocket::eSocketState::connected == ConnectState())
					{
						if (true != _rpc)
						{
#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
							if (NetworkConfig::GetUseNotAllowDuplicationLogin())
							{
								if (false == IsCompletedAuthentication())
								{
#ifdef _DEBUG
									SERVER_LOG(eServerLogType::eDebug, "CSocket::callback_receive(), IsCompletedAuthentication() is false, %s", GetRemoteInfo().c_str());
#endif
									return;
								}
							}
#endif

#ifdef _USE_NEW_NOT_ALLOW_PACKET
							if (_is_not_allow_packet_check && true == CheckHack(receive_command))
							{
								return;
							}
#else
							if (true == CheckHack(receive_command))
							{
								return;
							}
#endif
						}

						auto context = PacketContextPool::Pop();

						memcpy(context->buffer, &temp_packet[PACKET_HEADER_SIZE], (size_t)receive_packet_size - PACKET_HEADER_SIZE);

						context->cmd = static_cast<uint16_t>(receive_command);
						context->size = receive_packet_size - PACKET_HEADER_SIZE;
						context->socket = this;
						context->session_id = _session->GetID();
						//context->pop_time = util::mirTime::GetTickMilliCount();

						if (nullptr != _session && nullptr != _session->GetServer())
						{
							_session->GetServer()->ProcessPacketHook(context);
						}
						else
						{
							PacketContextPool::Push(context);
							if (nullptr == _session)
							{
								SERVER_LOG(eServerLogType::eWarning, "CSocket::callback_receive() - session is null !!!");
							}
							else if (nullptr == _session->GetServer())
							{
								SERVER_LOG(eServerLogType::eWarning, "CSocket::callback_receive() - server is null !!!");
							}
						}

#ifdef _DEBUG
						if (NetworkConfig::GetNetworkLogState())
						{
							SERVER_LOG(eServerLogType::eInfo, "CSocket::callback_receive() cmd : %d, size : %d, %s", static_cast<int32_t>(receive_command), context->size, GetRemoteInfo().c_str());
						}
#endif
					}
					else
					{
						SERVER_LOG(eServerLogType::eWarning, "CSocket::callback_receive() CSocket::eSocketState::connected != ConnectState");
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
	}

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
	bool CSocket::session_auth_process(CSession* const session, const int64_t& auid, const int64_t& cuid, const bool& reconnect)
	{
		if (NetworkConfig::GetUseNotAllowDuplicationLogin())
		{
			// socket reconnection
			if (false == IsCompletedAuthentication())
			{
				// reconnection 처리를 위해서 추가 해준다.
				if (reconnect)
				{
					if (session->IsDuplicationLoginForceClose())
					{
						SERVER_LOG(eServerLogType::eDebug, "CSocket::session_auth_process() session->IsDuplicationLoginForceClose() is true. auid : %lld, session_id : %lld", auid, session->GetID());
						return false;
					}

					networkController.SetConnectionWait(__func__, mir3d::util::uidGenerate.Get(util::CUidGenerate::eUid::mail), 0, auid, 0, true);
				}
			}

			if (false == IsCompletedAuthentication() && 0 == _socket_access_token)
			{
				// client 가 gate 에 처음 접속하는거다
				// client -> mp_session_auth_cs -> CSocket::SetSession()
				if ( false == reconnect && mir3d::mrpce_server_type::gate == mir3d::GameConfig::Server_Type() )
				{
					networkController.SetConnectionWait(__func__, mir3d::util::uidGenerate.Get(util::CUidGenerate::eUid::mail), 0, auid, cuid, true);
				}

#ifdef _USE_GLOBAL_SERVICE
#else
				if (false == reconnect && mir3d::mrpce_server_type::gate == mir3d::GameConfig::Server_Type() && 0 < cuid)
				{
					_mpay_socket_session = true;
				}
#endif

				if (false == _mpay_socket_session)
				{
					if (false == networkController.SetSocket(auid, this, _socket_access_token))
					{
						if (!(mir3d::mrpce_server_type::gate == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_community == mir3d::GameConfig::Server_Type()))
						{
							// ForceDisconnect(true);
							SERVER_LOG(eServerLogType::eDebug, "CSocket::session_auth_process() networkController.SetSocket() is false. auid : %lld, session_id : %lld", auid, session->GetID());
						}
						return false;
					}
				}

				SetCompletedAuthentication(true);
			}
			else
			{
				SERVER_LOG(eServerLogType::eDebug, "CSocket::session_auth_process() auid : %lld, session_id : %lld", auid, session->GetID());
			}
		}

		_socket_client_auid = auid;

		return true;
	}
#endif

	bool CSocket::CheckHack(const mir3d::mpe_cmd& packet_cmd)
	{
		auto now = util::mirTime::GetTickMilliCount();

#ifdef _USE_NEW_NOT_ALLOW_PACKET
		if (_update_not_allow_packet_check)
		{
			InitializeNotAllowPacket();

			_update_not_allow_packet_check = false;
		}

		if (0 <= _list_not_allow_packet_index)
		{
			int32_t max = static_cast<int32_t>(_list_not_allow_packet[_list_not_allow_packet_index].size());
			for (int32_t i = 0; i < max; i++)
			{
				if (_list_not_allow_packet[_list_not_allow_packet_index][i].info->cmd == packet_cmd)
				{

					if (0 != _list_not_allow_packet[_list_not_allow_packet_index][i].receive_time && static_cast<int32_t>((now - _list_not_allow_packet[_list_not_allow_packet_index][i].receive_time)) < _list_not_allow_packet[_list_not_allow_packet_index][i].info->limit_time)
					{
						SERVER_LOG(eServerLogType::eDebug, "too many %d, %sd", _list_not_allow_packet[_list_not_allow_packet_index][i].info->cmd, GetRemoteInfo().c_str());
						return true;
					}
					_list_not_allow_packet[_list_not_allow_packet_index][i].receive_time = now;
				}
			}
		}
#else	
		for (int32_t i = 0; i < NOT_ALLOW_PACKET_COUNT; i++)
		{
			if (_not_allow_packet[i].cmd == packet_cmd)
			{
				if (0 != _not_allow_packet[i].receive_time && now - _not_allow_packet[i].receive_time < _not_allow_packet[i].limit_time)
				{
					SERVER_LOG(eServerLogType::eWarning, "too many %d, %s", _not_allow_packet[i].cmd, GetRemoteInfo().c_str());
					return true;
				}
				_not_allow_packet[i].receive_time = now;
			}
		}
#endif

		if (NetworkConfig::GetHeartbeat_SpeedHackCheck())
		{
#ifdef _USE_PACKET_COUNT
			if (mpe_cmd::none < packet_cmd && mpe_cmd::cmd_max > packet_cmd)
			{
				_packet_receive_count[static_cast<int32_t>(packet_cmd)]++;
			}
#endif

			if (now < _speed_hack_check_time)
			{
				++_speed_hack_count;
			}
			else
			{
				_speed_hack_check_time = now + 1000;
				_speed_hack_count = 0;

#ifdef _USE_PACKET_COUNT				
				for (int32_t i = 0; i < static_cast<int32_t>(mpe_cmd::cmd_max); i++)
				{
					if (0 < _packet_receive_count[i])
					{
						SERVER_LOG(eServerLogType::eDebug, "@@@@ packet count, " << static_cast<mpe_cmd>(i) << " : " << _packet_receive_count[i];
						_speed_hack_count += _packet_receive_count[i];
					}
				}
				SERVER_LOG(eServerLogType::eDebug, "@@@@ packet total count : " << _speed_hack_count;
				
				_speed_hack_count = 0;

				memset(_packet_receive_count, 0x00, sizeof(int32_t) * static_cast<int32_t>(mpe_cmd::cmd_max));
#endif
			}

#ifdef _USE_PACKET_COUNT
#else
			if (NetworkConfig::GetHeartbeat_SpeedHackCheckCount() < _speed_hack_count)
			{
				SERVER_LOG(eServerLogType::eDebug, "too many packet per sec : %d, cmd : %d, %s", _speed_hack_count, static_cast<int32_t>(packet_cmd), GetRemoteInfo().c_str());

				return true;
			}
#endif
		}

		return false;
	}
	
	void CSocket::PostWrite(std::shared_ptr<CSocketWriteBuffer>& data)
	{
#ifdef _DEBUG
		if (NetworkConfig::GetNetworkLogState())
		{
			int32_t receive_packet_size;
			uint16_t receive_packet_cmd;
			const auto buffer = data->buffer->GetBufferPointer();

			memcpy(&receive_packet_size, buffer, PACKET_LENGTH_SIZE);
			memcpy(&receive_packet_cmd, &buffer[PACKET_LENGTH_SIZE], PACKET_COMMAND_SIZE);

			SERVER_LOG(eServerLogType::eInfo, "CSocket::PostWrite(), size : %d, cmd : %d, %s", receive_packet_size, receive_packet_cmd, GetRemoteInfo().c_str());
		}
#endif
		if (GetForceDisconnect())
		{
			SERVER_LOG(eServerLogType::eDebug, "CSocket::PostWrite() GetForceDisconnect() is true, %s", GetRemoteInfo().c_str());
			PostClose("CSocket::PostWrite(0)");
			return;
		}

		if (CSocket::eSocketState::connected == ConnectState())
		{
			if (SOCKET_BUFFER_CHECK_SIZE < data->buffer->GetBufferLength())
			{
				int64_t cuid = 0;
				if (nullptr != GetSession())
				{
					cuid = GetSession()->GetCuid();
				}
				SERVER_LOG(eServerLogType::eWarning, "CSocket::PostWrite() packet size over, size : [%d], cmd : [%d], auid : %lld, cuid : %lld", data->buffer->GetBufferLength(), data->buffer->GetSerializeCommand(), _socket_client_auid, cuid);
			}

			// 한 thread에서만 접근을 보장하지 말자.
			{
				std::lock_guard<std::mutex> lock(_mutex_list_write_buffer);
				_list_write_buffer[0]->emplace_back(data);
			}

			int32_t write_use_count_temp = 0;
			if (true == _write_use_count.compare_exchange_strong(write_use_count_temp, 1))
			{
				_curr_token_id = _token_id;
				_write_use_time = util::mirTime::GetTickMilliCount();
				_io_service.post(boost::bind(&CSocket::implement_write, this));
			}
			else
			{
				if (10000 < util::mirTime::GetTickMilliCount() - _write_use_time && 0 != _write_use_time)
				{
					SERVER_LOG(eServerLogType::eDebug, "CSocket::PostWrite use time is over. %sd", GetRemoteInfo().c_str());
					PostClose("CSocket::PostWrite(1)");
				}
			}
		}
		else
		{
			SERVER_LOG(eServerLogType::eDebug, "CSocket::PostWrite connect fail. %s", GetRemoteInfo().c_str());
			PostClose("CSocket::PostWrite(2)");
		}
	}

	void CSocket::implement_write(void)
	{
		if (CSocket::eSocketState::connected == ConnectState() && _curr_token_id == _token_id)
		{
			{
				std::lock_guard<std::mutex> lock(_mutex_list_write_buffer);
				auto temp = _list_write_buffer[1];
				_list_write_buffer[1] = _list_write_buffer[0];
				_list_write_buffer[0] = temp;
			}

			for (auto item : *_list_write_buffer[1])
			{
				_list_write_buffer_seq.emplace_back(boost::asio::buffer(item->buffer->GetBufferPointer(), item->buffer->GetBufferLength()));
			}

			if (false == _list_write_buffer_seq.empty())
			{
				if (CSocket::eSocketState::connected == ConnectState() && _curr_token_id == _token_id)
				{
					boost::asio::async_write(*_socket,
						_list_write_buffer_seq,
						boost::bind(&CSocket::callback_write, this, boost::asio::placeholders::error));
				}
				else
				{
					if (_curr_token_id != _token_id)
					{
						SERVER_LOG(eServerLogType::eDebug, "CSocket::write connect and token check fail. Token ID : %lld, Curr Token ID : %lld", _token_id, _curr_token_id);
					}

					SERVER_LOG(eServerLogType::eDebug, "CSocket::write connect and token check fail. %s", GetRemoteInfo().c_str());
					PostClose("CSocket::implement_write(0)");
				}
			}
			else
			{
				_write_use_count.exchange(0);
				_write_use_time = 0;
			}
		}
		else
		{
			if (_curr_token_id != _token_id)
			{
				SERVER_LOG(eServerLogType::eDebug, "CSocket::implement_write connect and token check fail. Token ID : %lld, Curr Token ID : %lld", _token_id, _curr_token_id);
			}
			
			SERVER_LOG(eServerLogType::eDebug, "CSocket::implement_write connect and token check fail. %s", GetRemoteInfo().c_str());

			PostClose("CSocket::implement_write(1)");
		}
	}

	void CSocket::callback_write(const boost::system::error_code& error_code)
	{	
		_list_write_buffer_seq.clear();
		_list_write_buffer[1]->clear();			// std::shared_ptr 이기 때문에 다 보내고 나서 해지를 해야한다.

		if (CSocket::eSocketState::connected == ConnectState() && _curr_token_id == _token_id)
		{
			if (error_code)
			{
				if (GetForceDisconnect())
				{
					SERVER_LOG(eServerLogType::eDebug, "CSocket::callback_write(_force_disconnect) %s, error No: %d, error Message: %s", GetRemoteInfo().c_str(), error_code.value(), error_code.message().c_str());
				}
				else if (CSocket::eSocketState::connected == ConnectState())
				{
					SERVER_LOG(eServerLogType::eDebug, "CSocket::callback_write() %sd, error No: %d, error Message: %s", GetRemoteInfo().c_str(), error_code.value(), error_code.message().c_str());
				}
				else
				{
					SERVER_LOG(eServerLogType::eDebug, "CSocket::callback_write() %s, what???", GetRemoteInfo().c_str());
				}

				PostClose("CSocket::callback_write(0)");
			}
			else
			{
				if (CSocket::eSocketState::connected == ConnectState())
				{
					if (false == _list_write_buffer[0]->empty())
					{
						implement_write();
					}
					else
					{
						_write_use_count.exchange(0);
						_write_use_time = 0;

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
						if (NetworkConfig::GetUseNotAllowDuplicationLogin())
						{
							if (GetForceDisconnect())
							{
								duplication_login_force_close_timer();
							}
						}
#endif				
					}
				}
			}
		}
		else
		{
			if (_curr_token_id != _token_id)
			{
				SERVER_LOG(eServerLogType::eDebug, "CSocket::callback_write connect and token check fail. Token ID : %lld, Curr Token ID : %lld", _token_id, _curr_token_id);
			}

			SERVER_LOG(eServerLogType::eDebug, "CSocket::callback_write connect and token check fail. %xd", GetRemoteInfo().c_str());
			PostClose("CSocket::callback_write(1)");
		}
	}

	void CSocket::HeartbeatCheck(void)
	{
		PostWrite(_heartbeat_cs_packet_buffer);

		_heartbeat_check_count.fetch_add(1);

		_heartbeat_deadline_timer.expires_from_now(boost::posix_time::seconds(NetworkConfig::GetHeartbeat_Interval()));

		_heartbeat_deadline_timer.async_wait(boost::bind(&CSocket::callback_heartbeatcheck_deadline, this, boost::asio::placeholders::error));

#ifdef _DEBUG
		SERVER_LOG(eServerLogType::eDebug, "CSocket::HeartbeatCheck() %s, timer async wait start.", GetRemoteInfo().c_str());
#endif
	}

	void CSocket::callback_heartbeatcheck_deadline(const boost::system::error_code& error_code)
	{
		if (error_code)
		{
			SERVER_LOG(eServerLogType::eDebug, "CSocket::callback_read_deadline() %s, error No: %d, error Message: %s", GetRemoteInfo().c_str(), error_code.value(), error_code.message().c_str());
			ForceDisconnect("CSocket::callback_heartbeatcheck_deadline(0)", true);
		}
		else if (0 < _heartbeat_check_count && _heartbeat_deadline_timer.expires_at() <= boost::asio::deadline_timer::traits_type::now())
		{
			int32_t count = _heartbeat_check_count.load();
			SERVER_LOG(eServerLogType::eDebug, "CSocket::callback_read_deadline() %s, read deadline time out. count : %d", GetRemoteInfo().c_str(), count);

			if (NetworkConfig::GetHeartbeat_CheckCount() < _heartbeat_check_count)
			{
				ForceDisconnect("CSocket::callback_heartbeatcheck_deadline(1)", true);
			}
			else
			{
				HeartbeatCheck();
			}
		}
		else
		{
#ifdef _DEBUG
			int32_t count = _heartbeat_check_count.load();
			SERVER_LOG(eServerLogType::eDebug, "CSocket::callback_read_deadline() %s, count : %d", GetRemoteInfo().c_str(), count);
#endif
		}
	}

#ifdef _USE_NEW_PACKET_ENCRYPTION
	// PACKET_HEADER_SIZE 제외하고 body 암호화로 처리
	int CSocket::decryption_receive_buffer(const int32_t& packet_size, uint8_t* packet_buffer)
	{
		_Crypt.DecryptRecv(packet_buffer, packet_size);

		return 0;
	}
#else
	int CSocket::handle_header_receive(void)
	{
		uint8_t* temp_buffer = nullptr;

		int32_t buffer_size = _socket_read_buffer->GetBuffer(temp_buffer);

		if (buffer_size < PACKET_HEADER_SIZE)
		{
			int32_t remain_size = PACKET_HEADER_SIZE - buffer_size;

			_Crypt.DecryptRecv(temp_buffer, buffer_size);

			if (remain_size > 0)
			{
				_Crypt.DecryptRecv(_socket_read_buffer->GetFirstBuffer(), remain_size);				
			}
		}
		else
		{
			_Crypt.DecryptRecv(temp_buffer, PACKET_HEADER_SIZE);
		}

		return 0;
	}
#endif

	int CSocket::handle_auth_session(int64_t auid, int clientSeed, std::string& digest)
	{
		Sha1Hash sha;
		//BigNumber K;

		uint32_t t = 0;
		uint32_t seed = _Seed;

		sha.UpdateData((uint8_t*)&auid, 8);
		sha.UpdateData((uint8_t*)&t, 4);
		sha.UpdateData((uint8_t*)&clientSeed, 4);
		sha.UpdateData((uint8_t*)&seed, 4);
		sha.UpdateBigNumbers(&_s, NULL);
		sha.Finalize();
		
		if (memcmp(sha.GetDigest(), digest.c_str(), 20))
		{
			mp_session_open_sc packet;
			packet.result = mpe_error::auth_session_failed;

			auto data = std::make_shared<CSocketWriteBuffer>();
			if (nullptr != data->buffer)
			{
				protocol::SerializeType(data->buffer, &packet);
				PostWrite(data);
			}

			SERVER_LOG(eServerLogType::eDebug, "CSocket::HandleAuthSession() fail, %s, auid : %lld", GetRemoteInfo().c_str(), auid);

			return -1;
		}

		//_Crypt.Init(&K);

		return 0;
	}

	bool CSocket::receive_header_check(uint8_t*& packet)
	{
		ClientPacketHeader& header = *((ClientPacketHeader*)packet);

		if ((header.size < PACKET_HEADER_SIZE) || (header.size > MAX_CLIENT_READ_BUFFER_SIZE))
		{
			SERVER_LOG(eServerLogType::eDebug, "CSocket::receive_header_check() fail size, %s, size : %u, cmd : %u", GetRemoteInfo().c_str(), header.size, header.cmd);
			return false;
		}

		//header.size -= 4;
		if (header.cmd >= static_cast<uint16_t>(mpe_cmd::cmd_max))
		{
			SERVER_LOG(eServerLogType::eDebug, "CSocket::receive_header_check() fail cmd_max, %s, size : %u, cmd : %us", GetRemoteInfo().c_str(), header.size, header.cmd);
			return false;
		}

		return true;
	}

	void CSocket::init_auth_crypt()
	{
		_Crypt.Init(&_s);
	}

	void CSocket::SendAuthServerSeed()
	{
		mp_auth_check_sc packet;
		packet.number = int32_t(mir3d::util::mirRandom.Get(1, 100000));
		packet.seed = _Seed;

		auto data = std::make_shared<CSocketWriteBuffer>();
		if (nullptr != data->buffer)
		{
			protocol::SerializeType(data->buffer, &packet);
			PostWrite(data);
		}

	}

	void CSocket::SendErrorMessage(const mpe_error& error_code, const mpe_cmd& error_command)
	{
		auto packet_buffer = std::make_shared<CSocketWriteBuffer>();
		if (packet_buffer->buffer)
		{
			mp_error_message_sc sc;
			sc.error = error_code;
						
			if (mpe_cmd::none != error_command)
			{
				sc.cmd = error_command;
			}

			protocol::SerializeType(packet_buffer->buffer, &sc);
			PostWrite(packet_buffer);
		}
	}

	void CSocket::SetLastPacketTime() 
	{		
		_last_packet_time.exchange(util::mirTime::GetTickMilliCount() + _check_packet_time);		
	}

	void CSocket::PushDisconnect() 
	{
		if (nullptr != _session)
		{
			SessionPool::PushDisconnect(_session);
		}
	}

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN  	
	void CSocket::duplication_login_force_close_timer(void)
	{
		_duplication_login_force_close_timer.expires_from_now(boost::posix_time::seconds(NetworkConfig::GetDuplicationLoginInterval()));
		_duplication_login_force_close_timer.async_wait(boost::bind(&CSocket::callback_duplication_login_force_close_timer, this, boost::asio::placeholders::error));
	}

	void CSocket::callback_duplication_login_force_close_timer(const boost::system::error_code& error_code)
	{
		SERVER_LOG(eServerLogType::eDebug, "CSocket::callback_duplication_login_force_close_timer() PostClose() call, %s", GetRemoteInfo().c_str());
		PostClose(__func__);
	}
#endif

	void CSocket::GhostSocketCheck(const uint64_t& current_time)
	{
		if (false == GetForceDisconnect() && GHOST_SOCKET_TIMEOUT < (current_time - GetSocketConnectedTime()))
		{
			SERVER_LOG(eServerLogType::eDebug, "CSocket::GhostSocketCheck() ForceDisconnect(true), %lld, %s", current_time - GetSocketConnectedTime(), GetRemoteInfo().c_str());
			ForceDisconnect(__func__, true);
		}
	}

}	// namespace mir3d