#include "stdafx_net.h"
#include "server.h"
#include "session.h"
#include <common/config.h>
#include <common/serverlogManager.h>

namespace mir3d
{
	CServer::CServer(const std::string& name, const int32_t& max_socket_count, const int32_t& worker_count) : _max_socket_count(max_socket_count), _worker_count(worker_count)
	{
		_name.assign(name);

		for (int32_t i = 0; i < worker_count; i++)
		{
			shared_ptr_io_service io_service(new boost::asio::io_service());

			_list_io_service.push_back(io_service);
		}

		_worker_thread = new CAsioThread(_list_io_service);

		_packetHookHandler = nullptr;
		_socketOpenedHandler = nullptr;
		_socketClosedHandler = nullptr;
		_sessionOpenedHandler = nullptr;
		_sessionClosedHandler = nullptr;
	}

	CServer::~CServer()
	{
		Destroy();
	}
	
	void CServer::Initialize()
	{
		_list_socket.reserve(_max_socket_count);
		
#ifdef _USE_NEW_NOT_ALLOW_PACKET
		InitNotAllowPacketInfo(true);
#endif

		for (int32_t i = 0; i < _max_socket_count; i++)
		{
			CSocket* socket = new CSocket(*_list_io_service[i % _worker_count], i, this);
	
#ifdef _USE_NEW_NOT_ALLOW_PACKET
			socket->SetNotAllowPacketCheck(_is_not_allow_packet_check);

			if (true == _is_not_allow_packet_check)
			{
				socket->InitializeNotAllowPacket();
			}
#endif

			_list_socket.push_back(socket);
			_queue_socket_id.Push(i);
		}
	}

	void CServer::Start(void)
	{
		if (nullptr != _worker_thread)
		{
			_worker_thread->Create(_name);
		}
	}

	void CServer::Destroy(void)
	{
		SAFE_DELETE(_worker_thread);
	}

	CSocket* CServer::GetSocket(int32_t& socket_id)
	{
		CSocket* socket = nullptr;
		for(int i = 0; i < _max_socket_count; i++)
		{
			// 소켓 인덱스 대기에서 꺼냄
			if (false == _queue_socket_id.Pop(socket_id))
			{
				return nullptr;
			}
			else
			{
				if (false == _list_socket[socket_id]->IsAllDone())
				{
					_queue_socket_id.Push(socket_id);
				}
				else
				{
					socket = _list_socket[socket_id];
					break;
				}
			}
		}

		if (nullptr == socket)
			return nullptr;

		socket->Initialize();

		return socket;
	}

	void CServer::ConnectedSocket(const int32_t& socket_id)
	{
		auto socket = _list_socket[socket_id];

		socket->Connected();

		// 연결된 소켓 관리 컨테이너에 추가
		{
			std::lock_guard<std::mutex> lock(_mutex_socket);
			_map_socket.insert(std::make_pair(socket_id, socket));
		}
	}

	void CServer::DisconnectedSocket(const int32_t& socket_id)
	{
		auto socket = _list_socket[socket_id];

		SocketClosed(socket);

		// 연결된 소켓 관리 컨테이너에서 제거
		{
			std::lock_guard<std::mutex> lock(_mutex_socket);			
			_map_socket.erase(socket_id);
		}

		if(nullptr != socket->GetSession())
		{
			std::lock_guard<std::mutex> lock(_mutex_session);
			_map_session.erase(socket->GetSession()->GetID());
		}
		
		// 소켓 인덱스 대기로..
		_queue_socket_id.Push(socket_id);
	}

	void CServer::Send(const int32_t socket_id, std::shared_ptr<CSocketWriteBuffer>& data)
	{
		if (_max_socket_count > socket_id)
		{
			_list_socket[socket_id]->PostWrite(data);
		}
	}

	void CServer::SendAll(std::shared_ptr<CSocketWriteBuffer>& data)
	{
		std::lock_guard<std::mutex> lock(_mutex_socket);

		for (const auto& iter : _map_socket)
		{
			iter.second->PostWrite(data);
		}
	}

	CSession* CServer::GetSession(int64_t session_id)
	{
		std::lock_guard<std::mutex> lock(_mutex_session);
		auto temp = _map_session.find(session_id);

		if (_map_session.end() != temp)
		{
			return temp->second;
		}

		return nullptr;
	}

	bool CServer::SetSession(CSession* session)
	{
		std::lock_guard<std::mutex> lock(_mutex_session);
		auto temp = _map_session.find(session->GetID());

		if (_map_session.end() != temp)
		{
			SERVER_LOG(eServerLogType::eWarning, "SetSession Already session : %lld", session->GetID());
			return false;
		}

		_map_session.insert(std::make_pair(session->GetID(), session));

		return true;
	}

#ifdef _USE_NEW_NOT_ALLOW_PACKET
	void CServer::InitNotAllowPacketInfo(bool initialize)
	{
		if (mrpce_server_type::game == GameConfig::Server_Type() || mrpce_server_type::world_game == GameConfig::Server_Type())
		{
			if (NetworkConfig::GetGame_PacketNotAllowCheck())
			{
				_is_not_allow_packet_check = true;

				auto list = NetworkConfig::GetGame_PacketNotAllowCheckInfo();

				std::vector<sNotAllowPacket> list_temp;

				for (int32_t i = 0; i < static_cast<int32_t>(list.size()); i++)
				{
					sNotAllowPacket packet;
					packet.cmd = (mir3d::mpe_cmd)list[i].cmd;
					packet.limit_time = list[i].limit_time;

					list_temp.push_back(packet);
				}

				SetNotAllowPacketInfo(list_temp);
			}
		}
		else if (mrpce_server_type::community == GameConfig::Server_Type() || mrpce_server_type::world_community == GameConfig::Server_Type())
		{
			if (NetworkConfig::GetCommunity_PacketNotAllowCheck())
			{
				_is_not_allow_packet_check = true;

				auto list = NetworkConfig::GetCommunity_PacketNotAllowCheckInfo();

				std::vector<sNotAllowPacket> list_temp;

				for (int32_t i = 0; i < static_cast<int32_t>(list.size()); i++)
				{
					sNotAllowPacket packet;
					packet.cmd = (mir3d::mpe_cmd)list[i].cmd;
					packet.limit_time = list[i].limit_time;

					list_temp.push_back(packet);
				}

				SetNotAllowPacketInfo(list_temp);
			}
		}

		if (false == initialize)
		{
			for (int32_t i = 0; i < static_cast<int32_t>(_list_socket.size()); i++)
			{
				_list_socket[i]->SetNotAllowPacketCheck(_is_not_allow_packet_check);
			}
		}
	}

	// 체크할 패킷 정보 셋팅
	// 초기화 및 운영툴로 실시간 처리
	void CServer::SetNotAllowPacketInfo(std::vector<sNotAllowPacket>& list)
	{
		std::vector<sNotAllowPacket*> list_temp;

		for (int32_t i = 0; i < static_cast<int32_t>(list.size()); i++)
		{
			auto packet = new sNotAllowPacket();
			packet->cmd = list[i].cmd;
			packet->limit_time = list[i].limit_time;

			list_temp.push_back(packet);
		}

		_list_not_allow_packet.push_back(list_temp);

		_list_not_allow_packet_index++;

		// 맨 처음 초기화 때는 호출하지 않는다.
		// 운영툴로 업데이트 되면 호출해서 모든 socket이 업데이트 되도록 처리한다.
		if (0 < _list_not_allow_packet_index)
		{
			// 모든 socket이 업데이트 되도록 설정
			for (int32_t i = 0; i < static_cast<int32_t>(_list_socket.size()); i++)
			{
				_list_socket[i]->UpdateNotAllowPacketCheck();
			}
		}
	}

	// 운영툴로 업데이트 되었다.
	void CServer::SetUpdateNotAllowPacket()
	{
		InitNotAllowPacketInfo();
	}

	// 각 socket 이 업데이트 해가는 함수
	void  CServer::UpdateNotAllowPacket(std::vector<std::vector<sSocketNotAllowPacket>>& list)
	{
		std::vector<sSocketNotAllowPacket> list_temp;
		for (int32_t i = 0; i < static_cast<int32_t>(_list_not_allow_packet[_list_not_allow_packet_index].size()); i++)
		{
			sSocketNotAllowPacket temp;

			temp.info = _list_not_allow_packet[_list_not_allow_packet_index][i];
			temp.receive_time = 0;

			list_temp.push_back(temp);
		}

		list.push_back(list_temp);
	}
#endif

}	// namespace mir3d