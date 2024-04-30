#pragma once

#include "server.h"
#include "./serialize/serialize_buffer_pool.h"
#include <common/serverlogManager.h>

namespace mir3d
{
	class CServer;
	class CSocket;

	class CSession
	{
	public:
		CSession() = default;
		~CSession() = default;
	
	public:
		void Initialize(const int64_t& session_id, CSocket* const socket, const bool& reconnect_session, const bool& reconnect_gate_session);
		void Release(void);
		void Destroy(void);		
		// void Disconnected(void);

	public:
		template<typename T> void Send(const T& packet)
		{
			if (nullptr != _socket && CSocket::eSocketState::connected == _socket->ConnectState())
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
						_socket->PostWrite(data);
					}
				}
			}
			else
			{
				if (nullptr == _socket)
				{
					SERVER_LOG(eServerLogType::eDebug, "CSession::Send() socket is nullptr. session id : %lld", _session_id);
				}
				else
				{
					SERVER_LOG(eServerLogType::eDebug, "CSession::Send() socket is closed. session id : %lld, state : %d, %s", _session_id, static_cast<int32_t>(_socket->ConnectState()), _socket->GetRemoteInfo().c_str());
				}

				// 2023.08.26 gogoblue74 send() 실패한 session은 socket close 처리한다.
				ForceDisconnect(__func__);
			}
		}

		void Send(std::shared_ptr<CSocketWriteBuffer>& data);

		void ForceDisconnect(const char* call_func);
		void HeartbeatCheck(void);
		int32_t GetHeartbeatCount();
		int64_t GetLastPacketTime();

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN  
		int64_t	GetSocketAccessToken(void);
		void SetDuplicationLoginForceClose(void);
		bool IsDuplicationLoginForceClose(void);
#endif
		int64_t	GetSocketAuid(void);
		void SetLastPacketTime();
		const std::string& GetRemoteInfo(void);
		const std::string& GetRemoteIp(void);
		void SetRedirection(bool is_redirection);
		bool IsRedirection();
		
	public:
		inline int64_t		GetID(void)						{ return _session_id; }	
		inline int32_t		GetSocketID(void)				{ return _socket_id; }		
		// inline void			SetTimeOut(int64_t time)		{ _timeout = time; }
		// inline int64_t		GetTimeOut(void)				{ return _timeout; }
		inline CServer*		GetServer(void)					{ return _server; }
		inline CSocket*		GetSocket(void)					{ return _socket; }
		inline std::string	GetUuid(void)					{ return _session_uuid; }
		inline void			SetCuid(const int64_t& cuid)	{ _session_cuid = cuid; }
		inline int64_t		GetCuid(void)					{ return _session_cuid; }
		inline bool			GetReconnectGateSession(void)	{ return _reconnect_gate_session; }
		inline void			ResetReconnectGateSession(void) { _reconnect_gate_session = false; }
		inline bool			CertifyUuid(std::string uuid)
		{
			if (0 == _session_uuid.compare(uuid))
				return true;
			return false;
		}

	private:
		CServer*		_server = nullptr;

		int64_t			_session_id = 0;
		int32_t			_socket_id = 0;

		bool			_is_connector = false;

		CSocket*		_socket = nullptr;

		bool			_is_redirection = false;
		std::string		_session_uuid;
		std::string		_string_temp = "";

		int64_t			_session_cuid = 0;

		bool			_reconnect_gate_session = false;

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN  		
		bool			_is_duplication_login_force_close = false;
#endif

	private:
		CSession(const CSession&) = delete;
		CSession& operator=(const CSession&) = delete;
		CSession(CSession&&) = delete;
		CSession& operator=(CSession&&) = delete;
	};
	
}	// namespace mir3d