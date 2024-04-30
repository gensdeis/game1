#include "stdafx_net.h"
#include "session.h"
#include "server.h"
#include "network.h"
#include <common/serverlogManager.h>
#include <protocol/mp_session_open.h>

#include <iostream>

#ifdef _WINDOWS
#include <Rpc.h>
#pragma comment(lib, "Rpcrt4.lib")
#endif

namespace mir3d
{
	void CSession::Initialize(const int64_t& session_id, CSocket* const socket, const bool& reconnect_session, const bool& reconnect_gate_session)
	{
		_server = socket->GetServer();
		_socket_id = socket->GetID();
		_is_connector = socket->IsConnecter();
		_socket = socket;
		_is_redirection = false;
		_reconnect_gate_session = reconnect_gate_session;
		_session_uuid.clear();

		{
#ifdef _WINDOWS
			UUID uuid;
			auto result = UuidCreate(&uuid);
			if (0 == result)
			{
				char* string_uuid;
				result = UuidToStringA(&uuid, (RPC_CSTR*)&string_uuid);

				if (0 == result)
				{
					_session_uuid.assign(string_uuid);
				}
			}

			if (0 != result)
#else
#endif			
			{
				_session_uuid.assign(std::to_string(mir3d::util::uidGenerate.GetSessionId()));
			}
		}

		if (0 == session_id)
		{
			_session_id = mir3d::util::uidGenerate.GetSessionId();  //randomGenerator::GetUid();			
		}
		else
		{
			_session_id = session_id;
		}

		if (false == _is_connector)
		{
			mir3d::mp_session_open_sc message;

			if (reconnect_session)
			{	
				message.result = mpe_error::session_reconnect;				
			}
			else
			{
				message.result = mpe_error::error_none;
			}

			message.session_id = _session_id;
			message.session_uuid = _session_uuid;

#ifdef _DEBUG
			SERVER_LOG(eServerLogType::eInfo, "CSession::Initialize() session id : %lld, uuid : %s", _session_id, _session_uuid.c_str());
#endif

			Send(message);
		}

		if (nullptr != _server)
		{
			_server->SessionOpened(this, reconnect_session);
		}
	}

	void CSession::Release(void)
	{
		_server = nullptr;
		_socket_id = -1;
		_is_connector = false;
		_is_redirection = false;
		_session_cuid = 0;
		_reconnect_gate_session = false;
	}

	void CSession::Destroy(void)
	{
		if (nullptr != _server)
		{
			_server->SessionClosed(this);
		}

		if (CSocket::eSocketState::connected == GetSocket()->ConnectState())
		{
			// GetSocket()->SetDisposalCloseSocket();
			// GetSocket()->PostClose();
			SERVER_LOG(eServerLogType::eDebug, "CSession::Destroy() socket state is eSocketState::connected, session id : %lld, auid : %lld, socket id : %lld", _session_id, GetSocket()->GetSocketAuid(), GetSocket()->GetID());
		}

		_session_id = 0;

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN  
		_is_duplication_login_force_close = false;
#endif
	}

	void CSession::Send(std::shared_ptr<CSocketWriteBuffer>& data)
	{
		if (nullptr != _socket && CSocket::eSocketState::connected == _socket->ConnectState())
		{
			_socket->PostWrite(data);
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
		}
	}

	void CSession::ForceDisconnect(const char* call_func)
	{
		if (nullptr != _socket)
		{
			_socket->ForceDisconnect(call_func, true);
		}
	}

	void CSession::HeartbeatCheck(void)
	{
		if (nullptr != _socket)
		{
			_socket->HeartbeatCheck();
		}
	}

	int32_t CSession::GetHeartbeatCount()
	{
		if (nullptr != _socket)
		{
			return _socket->GetHeartbeatCheckCount();
		}
		else
		{
			return -1;
		}
	}

	int64_t CSession::GetLastPacketTime()
	{
		if (nullptr != _socket)
		{
			return _socket->GetLastPacketTime();
		}

		return 0;
	}

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN  
	int64_t	CSession::GetSocketAccessToken(void)
	{
		if (nullptr != _socket)
		{
			return _socket->GetSocketAccessToken();
		}
		return 0;
	}

	void CSession::SetDuplicationLoginForceClose(void)
	{
		_is_duplication_login_force_close = true;
	}

	bool CSession::IsDuplicationLoginForceClose(void)
	{
		return _is_duplication_login_force_close;
	}
#endif
	int64_t	CSession::GetSocketAuid(void)
	{
		if (nullptr != _socket)
		{
			return _socket->GetSocketAuid();
		}
		return 0;
	}

	void CSession::SetLastPacketTime()
	{
		if (nullptr != _socket)
		{
			_socket->SetLastPacketTime();
		}
	}

	const std::string& CSession::GetRemoteInfo(void)
	{
		if (nullptr != _socket)
		{
			return _socket->GetRemoteInfo();
		}
		return _string_temp;
	}

	const std::string& CSession::GetRemoteIp(void)
	{
		if (nullptr != _socket)
		{
			return _socket->GetRemoteIp();
		}
		return _string_temp;
	}

	void CSession::SetRedirection(bool is_redirection)
	{
		_is_redirection = is_redirection;
	}

	bool CSession::IsRedirection()
	{
		return _is_redirection;
	}
}	// namespace mir3d