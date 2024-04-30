#pragma once

#include <common/serverlogManager.h>
#include "socketBuffer.h"

#include "auth/AuthCrypt.h"
#include "auth/BigNumber.h"
#include "auth/Sha1.h"

#define NOT_ALLOW_PACKET_COUNT  2

namespace mir3d
{
	class CSession;
	class CServer;
	
	struct ClientPacketHeader
	{
		uint32_t size;
		uint16_t cmd;
	};

#ifdef _USE_NEW_NOT_ALLOW_PACKET
	struct sNotAllowPacket
	{
	public:
		mir3d::mpe_cmd		cmd;
		int32_t				limit_time = 0;
	};

	struct sSocketNotAllowPacket
	{
	public:
		sNotAllowPacket*	info = nullptr;
		int64_t				receive_time = 0;
	};
#else
	struct sNotAllowPacket
	{
	public:
		mir3d::mpe_cmd	cmd;
		int64_t			receive_time = 0;
		int32_t			limit_time = 0;
	};
#endif 

	class CSocket
	{
	public:
		CSocket() = delete;
		CSocket(boost::asio::io_service& io_service, int32_t socket_id, CServer* server);
		~CSocket();

	public:
		bool Initialize(void);		
#ifdef _USE_NEW_NOT_ALLOW_PACKET
		void InitializeNotAllowPacket(void);
#endif
		void Release(void);
		void Destroy(void);

	public:
		void Connected(void);
		void PostClose(const char* call_func);
		void PostReceive(void);
		void PostWrite(std::shared_ptr<CSocketWriteBuffer>& data);

		template<typename T> void PostWrite(const T& packet)
		{
			if (nullptr != _socket && CSocket::eSocketState::connected == ConnectState())
			{
				auto data = std::make_shared<CSocketWriteBuffer>();
				if (nullptr != data->buffer)
				{
					protocol::SerializeType(data->buffer, &packet);
#ifdef _USE_PACKET_SERIALIZE_CHECK
					if (data->buffer->IsError())
					{
						SERVER_LOG(eServerLogType::eWarning, "protocol::Serialize() return false, CSession::Send(), cmd : [%d], size : [%d]", data->buffer->GetSerializeCommand(), data->buffer->GetErrorSerializeSize());
					}
					else
#endif
					{
						PostWrite(data);
					}
				}
			}
		}


	public:
		enum class eSocketState
		{
			none = 0,
			disconnect,
			connected,
			close,
		};

	public:
		void SetConnecter(void);
		bool SetSession(const int64_t& auid, const int64_t& cuid, const int64_t& session_id, const std::string& uuid);
		void ForceDisconnect(const char* call_func, const bool& post_close_socket = true, const bool& duplication_close_socket = false);
		void HeartbeatCheck(void);
		void SetLastPacketTime(void);
		int64_t GetLastPacketTime(void)
		{
			return _last_packet_time;
		}

		const std::string& GetRemoteInfo(void)
		{
			return _socket_remote_info;
		}
		
		const std::string& GetRemoteIp(void)
		{
			return _socket_remote_ip;
		}
				
		bool IsAllDone(void)
		{
			if (eSocketState::connected == ConnectState())
				return false;

			if (0 == _write_use_count)
			{
				if (0 < _list_write_buffer[0]->size() || 0 < _list_write_buffer[1]->size() || 0 < _list_write_buffer_seq.size())
					return false;
			}

			return true;
		}

		void PushDisconnect(void);
		void SetRemoteInfo(void);
		void SendAuthServerSeed(void);
		void SendErrorMessage(const mpe_error& error_code, const mpe_cmd& error_command = mpe_cmd::none);
		void GhostSocketCheck(const uint64_t& current_time);

	private:
		void SetRemoteIp(void)
		{
			if (eSocketState::connected == ConnectState())
			{
				_socket_remote_ip = _socket->remote_endpoint().address().to_string();
			}
		}

	public:
		inline boost::asio::ip::tcp::socket&	Socket(void)							{ return *_socket; }
		inline int32_t							GetID(void)								{ return _socket_id; }
		inline CSession*						GetSession(void)						{ return _session; }
		inline CServer*							GetServer(void)							{ return _server; }
		inline eSocketState						ConnectState(void) 
		{
			if (eSocketState::connected == _connect_state)
			{
				if (nullptr != _socket && _socket->is_open())
					return eSocketState::connected;
				else
					_connect_state = eSocketState::disconnect;
			}

			return _connect_state;
		} 
		inline void								SetConnectedState(eSocketState state)	{ _connect_state = state; }
		// Web Daemon 추가로 필요
		inline eSocketState						GetConnectedState(void)					{ return _connect_state; }

		inline bool								IsConnecter(void)						{ return _connecter; }
		inline bool								IsRpc(void)								{ return _rpc; }
		inline void								SetRpc(bool state)						{ _rpc = state; }
		inline const std::string&				GetRpcFullTag(void)						{ return _socket_rpc_fulltag; }
		inline void								SetRpcFullTag(const std::string& tag)	{ _socket_rpc_fulltag.assign(tag); }		
		inline int32_t							GetHeartbeatCheckCount(void)			{ return _heartbeat_check_count; }
		inline bool								GetForceDisconnect(void)				{ return _force_disconnect; }
		inline void								SetForceDisconnect(void)				{ _force_disconnect = true;}
		inline void								SetDisposalCloseSocket(void)			{ _disposal_close_socket = true; }
		inline bool								IsDummy(void)							{ return _dummy; }
		inline void								SetDummy(bool state)					{ _dummy = state; }
		inline uint64_t							GetSocketConnectedTime(void)			{ return _socket_connected_time; }

#ifdef _USE_NEW_NOT_ALLOW_PACKET
		void	SetNotAllowPacketCheck(bool check)										{ _is_not_allow_packet_check = check; }			// not allow packet 체크 여부 설정
		void	UpdateNotAllowPacketCheck(void)											{ _update_not_allow_packet_check = true; }		// not allow packet 목록 update 하기 위한 설정
#endif

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN  
		bool	IsCompletedAuthentication(void)											{ return _is_completed_authentication; }
		void	SetCompletedAuthentication(const bool& state)							{ _is_completed_authentication = state; }
		int64_t	GetSocketAccessToken(void)												{ return  _socket_access_token; }
		void	set_socket_access_token(const int64_t& access_token)					{ _socket_access_token = access_token; }
#endif

		int64_t GetSocketAuid(void)														{ return _socket_client_auid; }

		bool	IsMpaySocketSession(void)												{ return _mpay_socket_session; }

	private:			
		void setSocketOption(bool openflag = false);

		void implement_close(void);

		void implement_receive(void);
		void callback_receive(read_buffer* buffer, const boost::system::error_code& error_code, size_t bytes_transferred);
		void receive(read_buffer* buffer);

		void implement_write(void);
		void callback_write(const boost::system::error_code& error_code);
		
		void callback_heartbeatcheck_deadline(const boost::system::error_code& error_code);
		
#ifdef _USE_NEW_PACKET_ENCRYPTION
		int decryption_receive_buffer(const int32_t& packet_size, uint8_t* packet_buffer);
#else
		int handle_header_receive(void);
#endif
		int handle_auth_session(int64_t auid, int clientSeed, std::string& digest);

		bool receive_header_check(uint8_t*& packet);

		void init_auth_crypt();
		bool CheckHack(const mir3d::mpe_cmd& packet_cmd);

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN  	
		void duplication_login_force_close_timer(void);
		void callback_duplication_login_force_close_timer(const boost::system::error_code& error_code);

		bool session_auth_process(CSession* const session, const int64_t& auid, const int64_t& cuid, const bool& reconnect);
#endif
		void SetSocketConnectedTime(bool reset)
		{
			if (reset)
			{
				_socket_connected_time = 0;
			}
			else
			{
				_socket_connected_time = util::mirTime::GetTickMilliCount();
			}
		}

	private:
		boost::asio::io_service&							_io_service;
		boost::asio::ip::tcp::socket*						_socket = nullptr;
		int32_t												_socket_id;

		boost::asio::deadline_timer							_heartbeat_deadline_timer;
		std::atomic<int32_t>								_heartbeat_check_count = 0;

		eSocketState										_connect_state = eSocketState::none;
		bool												_connecter = false;
		bool												_rpc = false;
		bool												_force_disconnect = false;
		bool												_ai = false;
		bool												_dummy = false;

		CServer*											_server = nullptr;
		CSession*											_session = nullptr;						
		std::shared_ptr<CSocketWriteBuffer>					_heartbeat_cs_packet_buffer;

		SocketReadBuffer*									_socket_read_buffer = nullptr;
		read_buffer*										_read_buffer = nullptr;
		std::vector<boost::asio::const_buffer>				_list_write_buffer_seq;
		
		typedef std::vector<std::shared_ptr<CSocketWriteBuffer>> List_Write_Buffer;
		std::vector<List_Write_Buffer*>						_list_write_buffer;
		std::mutex											_mutex_list_write_buffer;
		
		std::atomic<int32_t>								_write_use_count = 0;
		
		int32_t												_check_packet_time = 0;
		std::atomic<int64_t>								_last_packet_time = 0;
		std::atomic<int64_t>								_write_use_time = 0;

#ifdef _USE_NEW_NOT_ALLOW_PACKET
		std::vector<std::vector<sSocketNotAllowPacket>>		_list_not_allow_packet;
		int32_t												_list_not_allow_packet_index = -1;
		bool												_is_not_allow_packet_check = false;
		bool												_update_not_allow_packet_check = false;
#ifdef _USE_PACKET_COUNT
		int32_t*											_packet_receive_count = nullptr;
#endif
#else
		sNotAllowPacket										_not_allow_packet[NOT_ALLOW_PACKET_COUNT];
#endif 	

		int32_t												_speed_hack_count = 0;
		uint64_t											_speed_hack_check_time = 0;

		uint64_t											_token_id = 0;
		uint64_t											_curr_token_id = 0;

		AuthCrypt											_Crypt;
		uint32_t											_Seed;
		BigNumber											_s;

		int32_t												_reconnect_try_count = 0;

		std::string											_socket_remote_info;
		std::string											_socket_remote_ip;
		std::string											_socket_rpc_fulltag;

		int64_t												_socket_client_auid = 0;

		uint64_t											_socket_connected_time = 0;

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN  		
		int64_t												_socket_access_token = 0;
		bool												_is_completed_authentication = false;

		boost::asio::deadline_timer							_duplication_login_force_close_timer;
#endif
		bool												_disposal_close_socket = false;		// 2023.08.15 session 반환시 연결이 살아 있는 경우 처리
		bool												_mpay_socket_session = false;

	private:
		CSocket(const CSocket&) = delete;
		CSocket& operator=(const CSocket&) = delete;
		CSocket(CSocket&&) = delete;
		CSocket& operator=(CSocket&&) = delete;
	};

}	// namespace mir3d