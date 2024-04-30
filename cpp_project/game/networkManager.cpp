#include "stdafx.h"
#include <common/mirapi.h>
#include <common/config.h>
#include <network/network.h>
#include <network/session.h>
#include <network/socket.h>
#include <protocol/mp_error_message.h>
#include "networkManager.h"
#include "gamePacketWorker.h"
#include "userManager.h"
#include "rpcManager.h"

#include <protocol/mp_test_game_server.h>
#include <protocol/mp_session_auth.h>

namespace mir3d
{
	void CAcceptServer::Initialize(void) 
	{ 
		if (mir3d::mrpce_server_type::game == mir3d::GameConfig::Server_Type() ||
						mir3d::mrpce_server_type::indun == mir3d::GameConfig::Server_Type() ||
#ifdef _USE_WORLD_GAME	
								mir3d::mrpce_server_type::world_game == mir3d::GameConfig::Server_Type() ||
#endif
										mir3d::mrpce_server_type::world_indun == mir3d::GameConfig::Server_Type() )
		{
			CAcceptor::PacketHookHandlerRegister(&OnGamePacketHookHandler);
			//CAcceptor::SocketHandlerRegister(&OnGameSocketOpened, nullptr, &OnGameSocketClosed);
			CAcceptor::SessionHandlerRegister(&OnGameSessionOpened, &OnGameSessionClosed);
		}
		else if (mir3d::mrpce_server_type::gate == mir3d::GameConfig::Server_Type())
		{
			CAcceptor::PacketHookHandlerRegister(&OnGatePacketHookHandler);
			CAcceptor::SocketHandlerRegister(&OnGateSocketOpened, nullptr, &OnGateSocketClosed);
			CAcceptor::SessionHandlerRegister(&OnGateSessionOpened, &OnGateSessionClosed);
		}

		CAcceptor::Initialize();
	}

	CNetworkManager::CNetworkManager(unsigned short port, int32_t session_count, int32_t worker_count) : _acceptor(port, session_count, worker_count)
	{
	}

	bool CNetworkManager::Initialize(void)
	{
		if (!(mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_community == mir3d::GameConfig::Server_Type()))
		{
			_acceptor.Initialize();
		}

		return true;
	}

	void CNetworkManager::Start(void)
	{
		if (!(mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_community == mir3d::GameConfig::Server_Type()))
		{
			_acceptor.Start();
		}
	}

	void CNetworkManager::Destroy(void)
	{
		if (!(mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_community == mir3d::GameConfig::Server_Type()))
		{
			_acceptor.Destroy();
		}

	}

	void CNetworkManager::SendErrorMessage(const mpe_cmd cmd, CSession* const session, const mpe_error error_code, bool reload, int64_t param1)
	{
		if (nullptr != session)
		{
			mp_error_message_sc message;
			message.error = error_code;

			int64_t cuid = 0;
			int32_t status = -1;
			int32_t action_state = -1;

			if (mpe_error::time_over_playingtime == error_code || mpe_error::time_over_shotdown == error_code)
			{
				message.cmd = mpe_cmd::error_message_sc;
			}
			else
			{
				message.cmd = cmd;

				switch (cmd)
				{
				case mpe_cmd::zone_enter_sc:
				case mpe_cmd::game_login_sc:
				case mpe_cmd::redirect_request_sc:					
					{
					SERVER_LOG(eServerLogType::eWarning, "@@@ SendError :: error_code [%d] ::cmd[%d] ::cuid[%lld] ::playstatus[%d] ::action_state[%d]", static_cast<int32_t>(error_code), static_cast<int32_t>(cmd), cuid, status, action_state);
					}
					break;
				default: break;
				}

				switch (error_code)
				{
				case mpe_error::zone_invalid_character:
				case mpe_error::zone_not_ready:
					{
					SERVER_LOG(eServerLogType::eWarning, "@@@ SendError :: error_code [%d] ::cmd[%d] ::cuid[%lld] ::playstatus[%d] ::action_state[%d]", static_cast<int32_t>(error_code), static_cast<int32_t>(cmd), cuid, status, action_state);
					}
					break;
				default: break;
				}

			}
			
			message.reload = reload;
			message.param1 = param1;
			
			session->Send(message);
		}
		else
		{
			SERVER_LOG(eServerLogType::eWarning, "session is null :: error_code [%d] ::cmd[%d]", static_cast<int32_t>(error_code), static_cast<int32_t>(cmd));
		}
	}

	void CNetworkManager::UpdateNotAllowPacket(void)
	{
		_acceptor.SetUpdateNotAllowPacket();

		NetworkConfig::SetUpdate_NotAllowCheck();
	}

	void OnGameSocketClosed(CSocket* socket)
	{
		auto session = socket->GetSession();

		if (nullptr == session)
		{
			return;
		}

		CUser* user = userManager.Get(socket->GetSession()->GetID());
		if (nullptr != user)
		{
			user->SetConnectState(false);
		}
	}

	void OnGameSessionOpened(CSession* session, const bool& reconnect)
	{	
		if (false == reconnect)
		{
			userManager.CreateUser(session);
		}
		else
		{
			userManager.ReconnectUser(session);
		}
	}

	void OnGameSessionClosed(CSession* session)
	{
		if (nullptr == session)
			return;

		userManager.DestroyUser(session);
	}

	void OnGamePacketHookHandler(packetContext* context)
	{
		auto user = userManager.Get(context->session_id);
		if (nullptr == user)
		{
			PacketContextPool::Push(context);	// packet drop
			return;
		}
		
		gamePacketWorker.PushSwitch(0, context);
	}

	//---------------------------------------------------------------------------------------------------------------------------------
	// gate socket
	//---------------------------------------------------------------------------------------------------------------------------------
	void OnGateSocketOpened(CSocket* socket)
	{
	}

	void OnGateSocketClosed(CSocket* socket)
	{
		
	}

	void OnGateSessionOpened(CSession* session, const bool& reconnect)
	{
	}

	void OnGateSessionClosed(CSession* session)
	{

	}

	void OnGatePacketHookHandler(packetContext* context)
	{

	}
}	// namespace mir3d

