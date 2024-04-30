#include "stdafx.h"
#include "rpcManager.h"
#include "rpc.h"
#include "networkManager.h"
#include <protocol/mrpc_server_contract_agenda_info.h>
#include <protocol/mrpc_global_party_governance_decide_info.h>
#include "gamePacketWorker.h"
#include "../game/main.h"
#include <protocol/mrpc_update_debug_print_rpcinfo.h>
#include <protocol/mrpc_heartbeat_check.h>
#include <protocol/rpc_protocol_enumstring.h>

namespace mir3d
{
	void CRpcAcceptor::Initialize(void)
	{
		if (mir3d::mrpce_server_type::game == mir3d::GameConfig::Server_Type() ||
			mir3d::mrpce_server_type::indun == mir3d::GameConfig::Server_Type() ||
#ifdef _USE_WORLD_GAME	
			mir3d::mrpce_server_type::world_game == mir3d::GameConfig::Server_Type() ||
#endif
			mir3d::mrpce_server_type::world_indun == mir3d::GameConfig::Server_Type())
		{
			CAcceptor::PacketHookHandlerRegister(&OnGameRpcAcceptorHookHandler);
		}
		else if (mir3d::mrpce_server_type::gate == mir3d::GameConfig::Server_Type())
		{
			CAcceptor::PacketHookHandlerRegister(&OnGateRpcAcceptorHookHandler);
		}
#ifdef _USE_WORLD_GAME
		else if (mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_community == mir3d::GameConfig::Server_Type())
#else
		else if (mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type())
#endif
		{
			CAcceptor::PacketHookHandlerRegister(&OnCommunityRpcAcceptorHookHandler);
		}
		
		CAcceptor::SocketHandlerRegister(&OnRpcAcceptorSocketOpened, nullptr, &OnRpcAcceptorSocketClosed);
		CAcceptor::SessionHandlerRegister(&OnRpcAcceptorSessionOpened, &OnRpcAcceptorSessionClosed);
		CAcceptor::Initialize();
	}

	void CRpcConnector::Initialize(void)
	{
		if (mir3d::mrpce_server_type::game == mir3d::GameConfig::Server_Type() ||
			mir3d::mrpce_server_type::indun == mir3d::GameConfig::Server_Type() ||
#ifdef _USE_WORLD_GAME	
			mir3d::mrpce_server_type::world_game == mir3d::GameConfig::Server_Type() ||
#endif
			mir3d::mrpce_server_type::world_indun == mir3d::GameConfig::Server_Type())
		{
			CConnector::PacketHookHandlerRegister(&OnGameRpcConnectorHookHandler);
		}
		else if (mir3d::mrpce_server_type::gate == mir3d::GameConfig::Server_Type())
		{
			CConnector::PacketHookHandlerRegister(&OnGateRpcConnectorHookHandler);
		}
#ifdef _USE_WORLD_GAME	
		else if (mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_community == mir3d::GameConfig::Server_Type())
#else
		else if (mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type())
#endif
		{
			CConnector::PacketHookHandlerRegister(&OnCommunityRpcConnectorHookHandler);
		}
			
		CConnector::SocketHandlerRegister(&OnRpcConnectorSocketOpened, &OnRpcConnectorSocketConnectFaild , &OnRpcConnectorSocketClosed);
		CConnector::SessionHandlerRegister(&OnRpcConnectorSessionOpened, &OnRpcConnectorSessionClosed);
		CConnector::Initialize();
	}

	CRpcManager::CRpcManager(unsigned short port, int32_t socket_count, int32_t worker_count, int32_t rpc_update_time) : 
												_acceptor(port, socket_count, worker_count), _connector("rpcManager", socket_count, worker_count), CThread(rpc_update_time, "rpcManager") // CWorker(worker_count, 1, 1) 
	{
		_map_fulltag.clear();
		_map_maintag.clear();
		_map_socket.clear();
	}

	void CRpcManager::Initialize(bool suspend)
	{
		// observer connect info set
		{
			auto info = GameConfig::Observer_Info();

			_observer_connect_info.index = 0;
			_observer_connect_info.ip = info->ip;
			_observer_connect_info.port = info->port;
			_observer_connect_info.type = mrpce_server_type::gmobserver;
		}

		// rpc & game info set
		{
			auto info = _update_redis_serverinfo_cs.alloc_info();

			// 클라이언트에 주는 정보
			auto service_info = info->alloc_service_info();
			service_info->state = GameConfig::Server_State();
			service_info->type = GameConfig::Server_Type();
			service_info->index = GameConfig::Server_Index();
			service_info->ip = GameConfig::Network_ListenIp();
			service_info->port = GameConfig::Network_ListenPort();
			// 데몬툴에 표시하는 정보
			service_info->svn_revision_number = GameConfig::Version_Svn_Revision_Number();
			service_info->version_number = GameConfig::Version_Version_Number();
			service_info->table_version_number = GameConfig::Version_Table_Version_Number();
			// RPC 연결 정보
			auto rpc_info = info->alloc_rpc_info();
			rpc_info->gid = GameConfig::Server_Gid();
			rpc_info->type = GameConfig::Server_Type();
			rpc_info->index = GameConfig::Server_Index();
			rpc_info->ip = GameConfig::Rpc_ListenIp();
			rpc_info->port = GameConfig::Rpc_ListenPort();
			// 월드서버 데몬툴에 이름을 이렇게...
			std::stringstream server_name;

			server_name << rpc_info->type << " [" << std::to_string(GameConfig::Server_Gid()) << "]";
			rpc_info->server_name.assign(server_name.str());

			server_name.str("");

			server_name << std::to_string(GameConfig::Server_Gid()) << "_" << rpc_info->type << "_" << std::to_string(GameConfig::Server_Index());
			_rpc_fulltag_string.assign(server_name.str());
					
#ifdef _USE_WORLD_GAME	
			// world game server connect info
			{
				auto service_info = _channel_update_zoneinfo_cs.alloc_service_info();
				service_info->ip.assign(GameConfig::Network_ListenIp());
				service_info->port = GameConfig::Network_ListenPort();
			}
#endif
		}
	
		_acceptor.Initialize();
		_connector.Initialize();

		NetworkConfig::SetServerName(_rpc_fulltag_string);

		CThread::Initialize(1, suspend);
	}

	void CRpcManager::Start(void)
	{		
		_acceptor.Start();
		_connector.Start();

		CThread::Start();
	}

	void CRpcManager::Destroy(void)
	{
		_acceptor.Destroy();
		_connector.Destroy();

		CThread::Destroy();

		for (auto map : _map_fulltag)
		{
			delete map.second;
		}

		_map_fulltag.clear();
		_map_maintag.clear();
		_map_socket.clear();
	}

	bool CRpcManager::Begin(void)
	{
		return true;
	}

	bool CRpcManager::Run(int32_t index)
	{
		Update();

		return true;
	}

	bool CRpcManager::End(void)
	{
		return true;
	}

	void CRpcManager::ConnectRpcServer(mrpcs_redis_rpcinfo rpcinfo)
	{
		PostConnect(rpcinfo);
	}

	void CRpcManager::UpdateConnectorRpcInfo(CSocket* const socket, const std::string& name, const int32_t& gid, const mrpce_server_type& type, const int32_t& index)
	{
		std::lock_guard<std::mutex> lock(_mutex_socket);
		auto iter = _map_socket.find(socket);

		if (_map_socket.end() != iter)
		{
			auto rpc = iter->second;

			socket->SetRpcFullTag(name);
			socket->SetRemoteInfo();

			rpc->SetGid(gid);
			rpc->SetType(type);
			rpc->SetIndex(index);

			SERVER_LOG(eServerLogType::eInfo, "CRpcManager::UpdateConnectorRpcInfo() gid : %d, type : %d, index : %d, name : %s", gid, static_cast<int32_t>(type), index, socket->GetRemoteInfo().c_str());
		}
	}

	void CRpcManager::ConnectRpcServer(std::vector<mrpcs_redis_rpcinfo>& list)
	{
// #ifdef _USE_GLOBAL_SERVICE	
		for (size_t i = 0; i < list.size(); i++)
		{
			// global server는 전부 연결
			if (mrpce_server_type::global_exchange == list[i].type || mrpce_server_type::global_governance == list[i].type)
			{
			}
			// world indun은 같은 월드 gid만 연결, 같은 월드의 서버들과 연결해야한다.
#ifdef _USE_WORLD_GAME	
			else if (mrpce_server_type::world_indun == GameConfig::Server_Type() || mrpce_server_type::world_game == mir3d::GameConfig::Server_Type() || mrpce_server_type::world_community == mir3d::GameConfig::Server_Type())
#else
			else if (mrpce_server_type::world_indun == GameConfig::Server_Type())
#endif			
			{
				if (GameConfig::World_Gid() != GameConfig::CreateWorldGid(list[i].gid))
				{
					continue;
				}

				if (GameConfig::Server_Type() == list[i].type && GameConfig::Server_Index() == list[i].index)
				{
					continue;
				}
			}
#ifdef _DELETE
			// 연결대상이 gid 가 다른경우  world server 들만 연결
			else if (GameConfig::Server_Gid() != list[i].gid)
			{
				if (mrpce_server_type::world_indun == list[i].type || mrpce_server_type::world_game_manager == list[i].type || mrpce_server_type::world_exchange == list[i].type)
				{
					if (GameConfig::World_Gid() != GameConfig::CreateWorldGid(list[i].gid))
					{
						continue;
					}
				}
				else
				{
					continue;
				}
			}
			// gid 가 같은 경우
			else
			{
				if (GameConfig::Server_Type() == list[i].type)
				{
					if (GameConfig::Server_Gid() == list[i].gid && GameConfig::Server_Index() == list[i].index)
					{
						continue;
					}
				}
			}
#endif
			// gate server는 
			// 해당 서버 gid 의 board, lobby
			// world board
			// global board
			else if (mrpce_server_type::gate == GameConfig::Server_Type())
			{
				if (GameConfig::Server_Gid() == list[i].gid)
				{
				}
#ifdef _USE_WORLD_GAME	
				else if (mrpce_server_type::world_game_manager == list[i].type || mrpce_server_type::world_community == list[i].type || mrpce_server_type::world_board == list[i].type || mrpce_server_type::global_board == list[i].type)
#else
				else if (mrpce_server_type::world_board == list[i].type || mrpce_server_type::global_board == list[i].type)
#endif
				{
				}
				else
				{
					continue;
				}
			}
			else if (GameConfig::Server_Gid() == list[i].gid)
			{
				if (GameConfig::Server_Type() == list[i].type && GameConfig::Server_Index() == list[i].index)
				{
					continue;
				}
			}

			PostConnect(list[i]);
		}
// #else	// !_USE_GLOBAL_SERVICE
///*
//		for (size_t i = 0; i < list.size(); i++)
//		{
//			if (list[i].type == mrpce_server_type::database || list[i].type == mrpce_server_type::gamemanager || list[i].type == mrpce_server_type::game || list[i].type == mrpce_server_type::lobby)
//			{
//				// if (/*GameConfig::Server_Type() == mrpce_server_type::world_game ||*/  GameConfig::Server_Type() == mrpce_server_type::world_indun)
//				if (/*GameConfig::Server_Type() == mrpce_server_type::world_game ||*/  GameConfig::Server_Type() == mrpce_server_type::world_indun || GameConfig::Server_Type() == mrpce_server_type::world_game_manager)
//				{
//					if (list[i].gid / 10 != GameConfig::World_Gid())
//						continue;
//				}
//				else
//				{
//					if (list[i].gid != GameConfig::Server_Gid())
//						continue;
//				}
//			}
//			else if (list[i].type == mrpce_server_type::logreceive)
//			{
//				if (list[i].gid != GameConfig::Server_Gid())
//					continue;
//			}
//
//			PostConnect(list[i]);
//		}
//*/
// #endif	// !_USE_GLOBAL_SERVICE
	}
	
	void CRpcManager::PostConnect(const mrpcs_redis_rpcinfo& redis_rpcinfo)
	{
		if (0 == redis_rpcinfo.state)
		{
			// gm server, gm observer는 무조건 연결
			if ((!(mrpce_server_type::gmobserver == redis_rpcinfo.type || mrpce_server_type::gmserver == redis_rpcinfo.type)))
			{
				SERVER_LOG(eServerLogType::eWarning, "PostConnect() mrpce_server_type : %d, is state is 0", static_cast<int32_t>(redis_rpcinfo.type));
				return;
			}
		}

		std::stringstream server_name;
		server_name << std::to_string(redis_rpcinfo.gid) << "_" << redis_rpcinfo.type << "_" << std::to_string(redis_rpcinfo.index);

		std::string try_connect_fulltag = server_name.str();
					
		// SERVER_LOG(eServerLogType::eInfo, "PostConnect() %s", try_connect_fulltag.c_str());
		
		// 연결되어 있는 rpc 인지 검사
		if (0 != _map_fulltag.size())
		{
			std::lock_guard<std::mutex> lock(_mutex_fulltag);
			auto temp = _map_fulltag.find(try_connect_fulltag);

			if (_map_fulltag.end() != temp)
			{
				return;
			}
		}

		// 연결 시도 중인 rpc 인지 검사
		{
			std::lock_guard<std::mutex> lock(_mutex_tryconnet);
			auto temp = _map_tryconnet.find(try_connect_fulltag);

			if (_map_tryconnet.end() != temp)
			{
				SERVER_LOG(eServerLogType::eDebug, "trying to rpc connect, full tag : %s, ip : %s:%d", try_connect_fulltag.c_str(), redis_rpcinfo.ip.c_str(), redis_rpcinfo.port);
				return;
			}

			_map_tryconnet.insert(std::make_pair(try_connect_fulltag, new CRpc(redis_rpcinfo)));
		}

		SERVER_LOG(eServerLogType::eDebug, "rpc connection try - full tag : %s, ip : %s:%d", try_connect_fulltag.c_str(), redis_rpcinfo.ip.c_str(), redis_rpcinfo.port);

		auto endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(redis_rpcinfo.ip), redis_rpcinfo.port);
		auto socket = _connector.PostConnect(endpoint, try_connect_fulltag);

		if (nullptr == socket)
		{
			std::lock_guard<std::mutex> lock(_mutex_tryconnet);
			auto temp = _map_tryconnet.find(try_connect_fulltag);

			if (_map_tryconnet.end() != temp)
			{
				SAFE_DELETE(temp->second);

				_map_tryconnet.erase(try_connect_fulltag);

				SERVER_LOG(eServerLogType::eDebug, "rpc connection try fail - full tag : %s, ip : %s:%d", try_connect_fulltag.c_str(), redis_rpcinfo.ip.c_str(), redis_rpcinfo.port);
			}
		}
	}

	// PostConnect() 통해서 연결된 소켓만 들어온다.
	void CRpcManager::Connected(CSocket* socket)
	{
		CRpc* rpc = nullptr;

		{
			std::lock_guard<std::mutex> lock(_mutex_tryconnet);
			auto temp = _map_tryconnet.find(socket->GetRpcFullTag());

			if (_map_tryconnet.end() != temp)
			{
				rpc = temp->second;
			}
		}		

		if (nullptr != rpc)
		{
			// socket map
			{
				std::lock_guard<std::mutex> lock(_mutex_socket);
				auto temp = _map_socket.find(socket);

				if (_map_socket.end() != temp)
				{
					SERVER_LOG(eServerLogType::eWarning, "CRpcManager::Connected() already exists socket : %s", rpc->GetFullTag().c_str());
					return;
				}

				_map_socket.insert(std::make_pair(socket, rpc));

				SERVER_LOG(eServerLogType::eInfo, "CRpcManager::Connected() _map_socket add, %s", rpc->GetFullTag().c_str());
			}

			// main tag
			{
				std::lock_guard<std::mutex> lock(_mutex_maintag);
				auto temp = _map_maintag.find(rpc->GetType());

				if (_map_maintag.end() != temp)
				{
					temp->second.emplace_back(rpc);
					SERVER_LOG(eServerLogType::eInfo, "CRpcManager::Connected() _map_maintag add, %s, size : %d", rpc->GetFullTag().c_str(), temp->second.size());
				}
				else
				{
					std::vector<CRpc*> list;

					list.emplace_back(rpc);

					_map_maintag.insert(std::make_pair(rpc->GetType(), list));
					SERVER_LOG(eServerLogType::eInfo, "CRpcManager::Connected() _map_maintag insert : %s", rpc->GetFullTag().c_str());
				}
			}

			// full tag
			{
				std::lock_guard<std::mutex> lock(_mutex_fulltag);
				auto temp = _map_fulltag.find(rpc->GetFullTag());

				if (_map_fulltag.end() != temp)
				{
					SERVER_LOG(eServerLogType::eWarning, "CRpcManager::Connected() _map_fulltag already exists rpc : %s", rpc->GetFullTag().c_str());
				}
				else
				{
					_map_fulltag.insert(std::make_pair(rpc->GetFullTag(), rpc));

					SERVER_LOG(eServerLogType::eInfo, "CRpcManager::Connected() _map_fulltag add, %s", rpc->GetFullTag().c_str());
				}
			}

			// heartbeat socket
			{
				std::lock_guard<std::mutex> lock(_mutex_socket_heartbeat);
				auto temp = _map_socket_heartbeat.find(rpc->GetHeartbeatUid());

				if (_map_socket_heartbeat.end() != temp)
				{
					SERVER_LOG(eServerLogType::eWarning, "CRpcManager::Connected() already exists socket : %s", rpc->GetFullTag().c_str());
					return;
				}

				_map_socket_heartbeat.insert(std::make_pair(rpc->GetHeartbeatUid(), rpc));

				SERVER_LOG(eServerLogType::eInfo, "CRpcManager::Connected() _map_socket_heartbeat add, %s", rpc->GetFullTag().c_str());
			}
		}
		else
		{
			SERVER_LOG(eServerLogType::eWarning, "CRpcManager::Connected() not found rpc : %s", socket->GetRemoteInfo().c_str());
		}

		{
			std::lock_guard<std::mutex> lock(_mutex_tryconnet);
			_map_tryconnet.erase(socket->GetRpcFullTag());
		}
	}

	void CRpcManager::ConnectFailed(CSocket* socket)
	{
		std::lock_guard<std::mutex> lock(_mutex_tryconnet);
		auto itr = _map_tryconnet.find(socket->GetRpcFullTag());
		if (itr == _map_tryconnet.end())
		{
			return;
		}

		SAFE_DELETE(itr->second);
		_map_tryconnet.erase(itr);
	}

	void CRpcManager::Disconnected(CSocket* socket, bool acceptor)
	{
		CRpc* rpc = nullptr;
		
		{
			std::lock_guard<std::mutex> lock(_mutex_socket);
			auto temp = _map_socket.find(socket);

			if (_map_socket.end() != temp)
			{
				rpc = temp->second;

				// heartbeat socket
#ifdef _NOT_USE_HEARTBEAT    // 2023.10.14 gogoblue74 - accept socket 은 heartbeat 안함
#endif
				if (false == acceptor)
				{
					std::lock_guard<std::mutex> lock(_mutex_socket_heartbeat);
					auto temp = _map_socket_heartbeat.find(rpc->GetHeartbeatUid());

					if (_map_socket_heartbeat.end() != temp)
					{
						_map_socket_heartbeat.erase(rpc->GetHeartbeatUid());

						SERVER_LOG(eServerLogType::eInfo, "CRpcManager::Disconnected() _map_socket_heartbeat : %s", socket->GetRemoteInfo().c_str());
					}
					else
					{
						SERVER_LOG(eServerLogType::eWarning, "CRpcManager::Disconnected() _map_socket_heartbeat not found rpc : %s", socket->GetRemoteInfo().c_str());
					}
				}

				_map_socket.erase(socket);

				if (acceptor)
				{
					SERVER_LOG(eServerLogType::eInfo, "CRpcManager::Disconnected() acceptor, %s", socket->GetRemoteInfo().c_str());
					SAFE_DELETE(rpc);
					return;
				}

				SERVER_LOG(eServerLogType::eInfo, "CRpcManager::Disconnected() %s", socket->GetRemoteInfo().c_str());
			}
			else
			{
				SERVER_LOG(eServerLogType::eDebug, "CRpcManager::Disconnected() _map_socket not found rpc, acceptor : %d, %s", acceptor, socket->GetRemoteInfo().c_str());
			}
		}
		
		if (nullptr != rpc)
		{
			// main tag
			{
				std::lock_guard<std::mutex> lock(_mutex_maintag);
				auto temp = _map_maintag.find(rpc->GetType());

				if (_map_maintag.end() != temp)
				{
					auto iter = temp->second.begin();
					for (; temp->second.end() != iter; ++iter)
					{
						if (rpc->GetIndex() == (*iter)->GetIndex() && rpc->GetGid() == (*iter)->GetGid())
						{
#ifdef _CHANNEL

#ifdef _USE_WORLD_GAME	
							if (mrpce_server_type::world_indun == GameConfig::Server_Type() || mrpce_server_type::world_game == mir3d::GameConfig::Server_Type())
#else
							if (mrpce_server_type::world_indun == GameConfig::Server_Type())
#endif	

							
							{
								if (rpc->GetType() == mrpce_server_type::world_game_manager)
								{
									SetChannelInitializeComplete(false);
								}
							}
							else
							{
								if (rpc->GetType() == mrpce_server_type::gamemanager)
								{
									SetChannelInitializeComplete(false);
								}
							}
#endif

							temp->second.erase(iter);

							SERVER_LOG(eServerLogType::eInfo, "CRpcManager::Disconnected() _map_maintag list erase : %s, size : %d", socket->GetRemoteInfo().c_str(), temp->second.size());

							// 남은 연결이 없는 tag 는 삭제 처리.
							if (temp->second.empty())
							{
								_map_maintag.erase(rpc->GetType());

								SERVER_LOG(eServerLogType::eInfo, "CRpcManager::Disconnected() _map_maintag list erase : %d", static_cast<int32_t>(rpc->GetType()));
							}

							break;
						}
					}
				}
				else
				{
					SERVER_LOG(eServerLogType::eWarning, "CRpcManager::Disconnected() _map_maintag not found rpc : %s", socket->GetRemoteInfo().c_str());
				}
			}

			// full tag
			{
				std::lock_guard<std::mutex> lock(_mutex_fulltag);
				auto temp = _map_fulltag.find(rpc->GetFullTag());

				if (_map_fulltag.end() != temp)
				{
					_map_fulltag.erase(rpc->GetFullTag());

					SERVER_LOG(eServerLogType::eInfo, "CRpcManager::Disconnected() _map_fulltag : %s", socket->GetRemoteInfo().c_str());
				}
				else
				{
					SERVER_LOG(eServerLogType::eWarning, "CRpcManager::Disconnected() _map_fulltag not found rpc : %s", socket->GetRemoteInfo().c_str());
				}
			}

			// 2023.02.01 여기서 이러시면 안된다... gogoblue74  머.. 메모리.. 걍. 삭제 안되도 되는걸로.
			/*
			std::chrono::milliseconds duration(10);
			int32_t check_loop = 0;
			while(rpc->GetUseState())
			{				
				std::this_thread::sleep_for(duration);
				check_loop++;

				if (5 < check_loop)
				{
					return;	// gogoblue74 delete 시키자 않아도 된다.
				}
			}

			SAFE_DELETE(rpc);
			*/
		}		
	}

	void CRpcManager::ConnectedSession(CSession* session, bool acceptor)
	{
		CRpc* rpc = nullptr;

		if (acceptor)
		{
			std::lock_guard<std::mutex> lock(_mutex_socket);
			auto temp = _map_socket.find(session->GetSocket());

			if (_map_socket.end() != temp)
			{
				SERVER_LOG(eServerLogType::eWarning, "CRpcManager::ConnectedSession() already exists acceptor socket");
			}
			else
			{
				rpc = new CRpc();

				if (nullptr != rpc)
				{
					rpc->SetSession(session);

					_map_socket.insert(std::make_pair(session->GetSocket(), rpc));

					SERVER_LOG(eServerLogType::eInfo, "CRpcManager::ConnectedSession(acceptor), type : %d, %s", rpc->GetType(), session->GetSocket()->GetRemoteInfo().c_str());

#ifdef _NOT_USE_HEARTBEAT    // 2023.10.14 gogoblue74 - accept socket 은 heartbeat 안함
					// heartbeat socket
					{
						std::lock_guard<std::mutex> lock(_mutex_socket_heartbeat);
						auto temp = _map_socket_heartbeat.find(rpc->GetHeartbeatUid());

						if (_map_socket_heartbeat.end() != temp)
						{
							SERVER_LOG(eServerLogType::eWarning, "CRpcManager::ConnectedSession(acceptor), _map_socket_heartbeat, type : %d, %s", rpc->GetType(), session->GetSocket()->GetRemoteInfo().c_str());
						}
						else
						{
							_map_socket_heartbeat.insert(std::make_pair(rpc->GetHeartbeatUid(), rpc));
							SERVER_LOG(eServerLogType::eInfo, "CRpcManager::ConnectedSession(acceptor), _map_socket_heartbeat, type : %d, %s", rpc->GetType(), session->GetSocket()->GetRemoteInfo().c_str());
						}
					}
#endif
				}
				else
				{
					SERVER_LOG(eServerLogType::eWarning, "CRpcManager::ConnectedSession() new CRpc() is null.");
				}
			}
		}
		else
		{
			std::lock_guard<std::mutex> lock(_mutex_socket);
			auto temp = _map_socket.find(session->GetSocket());

			if (_map_socket.end() != temp)
			{
				rpc = temp->second;

				if (nullptr != rpc)
				{
					rpc->SetSession(session);
										
					// gm observer 연결시
					if (mrpce_server_type::gmobserver == rpc->GetType())
					{
						_observer_connected = true;

						{
							mrpc_get_redis_rpcinfo_cs cs;
							cs.type = mir3d::mrpce_server_type::gmserver;
							RpcSend(mrpce_server_type::gmobserver, cs);
							SERVER_LOG(eServerLogType::eInfo, "gm server info requst");
						}
					}
					
					if (mrpce_server_type::gmserver == rpc->GetType())
					{
						if (false == GameConfig::Server_TableLocalLoad())
						{
							SendTableLoad(-1);
						}

						{
							mrpc_server_info_cs req;
							req.server_type = GameConfig::Server_Type();
							req.server_index = GameConfig::Server_Index();
							RpcSend(mrpce_server_type::gmserver, req);
							SERVER_LOG(eServerLogType::eInfo, "mrpc_server_info_cs() requst, server type : %d, index : %d", static_cast<int32_t>(req.server_type), req.server_index);
						}

						{
							mrpc_contents_onoff_list_cs cs;							
							RpcSend(mrpce_server_type::gmserver, cs);
							SERVER_LOG(eServerLogType::eInfo, "mrpc_contents_onoff_list_cs() requst");
						}
					}

#ifdef _USE_WORLD_GAME	
					if (mrpce_server_type::world_indun == GameConfig::Server_Type() || mrpce_server_type::world_game == mir3d::GameConfig::Server_Type())
#else
					if (mrpce_server_type::world_indun == GameConfig::Server_Type())
#endif
					{
						if (mrpce_server_type::world_game_manager == rpc->GetType())
						{
							SetReconnectComplete(true);
						}
					}
				}
				else
				{
					SERVER_LOG(eServerLogType::eDebug, "CRpcManager::ConnectedSession() rpc is null");
				}
			}
			else
			{
				SERVER_LOG(eServerLogType::eDebug, "CRpcManager::ConnectedSession() not found socket");
			}
		}
	}

	void CRpcManager::DisconnectedSession(CSession* session)
	{
	}

	void CRpcManager::SendTableLoad(int index)
	{
		mrpc_table_load_cs cs;
		
		cs.load_index = index;

		SERVER_LOG(eServerLogType::eInfo, "SendTableLoad() - %d", index);

		RpcSend(mrpce_server_type::gmserver, cs);
	}

	CRpc* CRpcManager::GetRpc(CSocket* socket)
	{
		if (nullptr == socket)
			return nullptr;

		CRpc* rpc = nullptr;
		
		std::lock_guard<std::mutex> lock(_mutex_socket);
		auto temp = _map_socket.find(socket);

		if (_map_socket.end() != temp)
		{
			rpc = temp->second;
#ifdef _NOT_USE
			rpc->SetUse();
#endif
		}

		return rpc;
	}

	CRpc* CRpcManager::GetRpc(const mrpce_server_type& server_type)
	{
		if(0 ==_map_maintag.size() )
			return nullptr;

		std::lock_guard<std::mutex> lock(_mutex_maintag);
		auto list = _map_maintag.find(server_type);

		if (_map_maintag.end() != list)
		{
			auto index = static_cast<int32_t>(list->second.size());

			if (0 == index)
				return nullptr;

			if (1 < index)
				index = mir3d::util::mirRandom.Get(0, index - 1);
			else
				index = 0;

			auto rpc = list->second[index];
#ifdef _NOT_USE
			rpc->SetUse();
#endif
			return rpc;
		}

		return nullptr;
	}

	CRpc* CRpcManager::GetRpc(const mrpce_server_type& server_type, const int32_t& index)
	{
		if (0 == _map_maintag.size())
			return nullptr;

		std::lock_guard<std::mutex> lock(_mutex_maintag);
		auto list = _map_maintag.find(server_type);

		if (_map_maintag.end() != list)
		{
			for (size_t i = 0; i < static_cast<int32_t>(list->second.size()); i++)
			{
				auto rpc = list->second[i];

				if (rpc->GetIndex() != index)
					continue;
#ifdef _NOT_USE
				rpc->SetUse();
#endif
				return rpc;
			}
		}

		return nullptr;
	}

	CRpc* CRpcManager::GetRpc(const int32_t& gid, const mrpce_server_type& server_type, const int32_t& index)
	{
		std::stringstream server_name;
		server_name << std::to_string(gid) << "_" << server_type << "_" << std::to_string(index);

		std::string fulltag = server_name.str();

		CRpc* rpc = nullptr;

		std::lock_guard<std::mutex> lock(_mutex_fulltag);
		auto map = _map_fulltag.find(fulltag);
		
		if (_map_fulltag.end() != map)
		{
			rpc = map->second;
#ifdef _NOT_USE
			rpc->SetUse();
#endif
		}

		return rpc;
	}

	void CRpcManager::GetAllRpc(const mrpce_server_type& server_type, std::vector<CRpc*>& list_server)
	{
		if (0 == _map_maintag.size())
			return;

		std::lock_guard<std::mutex> lock(_mutex_maintag);
		auto list = _map_maintag.find(server_type);

		if (_map_maintag.end() != list)
		{
			for (size_t i = 0; i < static_cast<int32_t>(list->second.size()); i++)
			{
				auto rpc = list->second[i];
#ifdef _NOT_USE
				rpc->SetUse();
#endif
				list_server.push_back(rpc);
			}
		}
	}	
	
	void CRpcManager::GetRpcList(std::string& strRpcList)
	{
		std::lock_guard<std::mutex> lock(_mutex_maintag);

		for (auto& itr : _map_maintag)
		{
			int serverType = (int)itr.first;
			if (strRpcList.length() > 0) strRpcList += ",";
			if (serverType > 0) strRpcList += std::to_string((int)itr.first);
		}
	}

	CRpc* CRpcManager::GetRpcByGid(const mrpce_server_type& server_type, const int32_t& gid)
	{
		if (0 == _map_maintag.size())
			return nullptr;

		std::lock_guard<std::mutex> lock(_mutex_maintag);
		auto list = _map_maintag.find(server_type);

		if (list == _map_maintag.end())
			return nullptr;

		if (true == list->second.empty())
			return nullptr;

		for (const auto& rpc : list->second)
		{
			if (rpc->GetGid() == gid)
			{
#ifdef _NOT_USE
				rpc->SetUse();
#endif
				return rpc;
			}
		}

		return nullptr;
	}

	CRpc* CRpcManager::GetRpcWorld(const mrpce_server_type& server_type, const int32_t& gid)
	{
		if (0 == _map_maintag.size())
		{
			return nullptr;
		}

		std::lock_guard<std::mutex> lock(_mutex_maintag);
		{
			auto iter = _map_maintag.find(server_type);

			if (_map_maintag.end() != iter)
			{
				auto list = iter->second;

				if (true == list.empty())
				{
					return nullptr;
				}

#ifdef _USE_WORLD_GAME	
				if (mrpce_server_type::world_game == GameConfig::Server_Type() || mrpce_server_type::world_indun == GameConfig::Server_Type())
#else
				if (mrpce_server_type::world_indun == GameConfig::Server_Type())
#endif
				{
					for (const auto& rpc : list)
					{
						if (rpc->GetGid() == gid)
						{
#ifdef _NOT_USE
							rpc->SetUse();
#endif
							return rpc;
						}
					}
				}
				else
				{
					auto index = static_cast<int32_t>(list.size());

					if (1 < index)
						index = mir3d::util::mirRandom.Get(0, index - 1);
					else
						index = 0;

					auto rpc = list[index];
#ifdef _NOT_USE
					rpc->SetUse();
#endif
					return rpc;
				}
			}
		}

		return nullptr;
	}

	void CRpcManager::SendChannelCreateInfo(bool is_first)
	{		
#ifdef _CHANNEL
		CRpc* rpc = nullptr;

#ifdef _USE_WORLD_GAME	
		if (mrpce_server_type::world_indun == GameConfig::Server_Type() || mrpce_server_type::world_game == GameConfig::Server_Type())
#else
		if (mrpce_server_type::world_indun == GameConfig::Server_Type())
#endif

			rpc = rpcManager.GetRpc(mrpce_server_type::world_game_manager);
		else
			rpc = rpcManager.GetRpc(mrpce_server_type::gamemanager);

		if (nullptr != rpc && true == rpc->GetSession())
		{
			auto& infos = tableManager.GetServerInfo();

			_channel_update_zoneinfo_cs.set_info_list(&infos);
			_channel_update_zoneinfo_cs.max_play_user = static_cast<int16_t>(GameConfig::Game_MaxPlayUser());

			auto send_data = std::make_shared<CSocketWriteBuffer>();
			if (nullptr != send_data->buffer)
			{
				protocol::SerializeType(send_data->buffer, &_channel_update_zoneinfo_cs);
#ifdef _USE_PACKET_SERIALIZE_CHECK
				if (send_data->buffer->IsError())
				{
					SERVER_LOG(eServerLogType::eWarning, "protocol::Serialize() return false, CRpcManager::SendChannelCreateInfo() cmd : [%d], size : [%d]", send_data->buffer->GetSerializeCommand(), send_data->buffer->GetErrorSerializeSize());
				}
				else
#endif
				{
					rpc->Send(send_data);
				}

				if (is_first)
				{
					SetReconnectComplete(false);
					SetChannelInitializeComplete(true);					
				}
			}

			if (0 < infos.list.size())
			{
				for (const auto& info : infos.list)
				{
					if (0 == info.channel_uid)
					{
						SERVER_LOG(eServerLogType::eWarning, "SendChannelCreateInfo() :: channel_uid is 0 :: id [%d], table_id [%d]", info.id, info.table_id);
					}
				}
			}

			if (is_first && 0 < infos.list.size())
			{				
				mrpc_server_use_count_cs rpc_req;
				rpc_req.server_type = GameConfig::Server_Type();
				rpc_req.server_index = GameConfig::Server_Index();
				rpc_req.is_first = is_first;

				for (const auto& info : infos.list)
				{
					if (0 == info.channel_uid)
						continue;

					rpc_req.channel_uid = info.channel_uid;
					rpc_req.table_id = info.table_id;

					rpc->Send(rpc_req);
				}
			}
		}
#endif
	}

	void CRpcManager::SendChannelUpdateInfo(int64_t channel_uid, int16_t user_count)
	{
		// 유저 카운트 update 는 채널에 + , 서버에 + 둘다 해줘야 함.

		SetSendChannelUpdate(false);
	}

	void CRpcManager::Update()
	{
		auto current_time = mir3d::util::mirTime::GetTickMilliCount();

		auto observer = GetRpc(mrpce_server_type::gmobserver);
		if (nullptr == observer)
		{
			PostConnect(_observer_connect_info);
		}
		else if (observer->GetSession())
		{
			UpdateRpcInfo(observer, current_time);

			UpdateContentsInfo(current_time);

			UpdateRpcHeartbeat(current_time);
		}
		else
		{
			SERVER_LOG(eServerLogType::eWarning, "CRpcManager::Update() :: observer->GetSession() is nullptr !!!");
		}

		if (UPDATE_SEND_CHANNEL_CREATE_INFO <= current_time - _update_send_channel_create_info)
		{
			_update_send_channel_create_info = current_time;

#ifdef _USE_WORLD_GAME	
			if (!(mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::gate == mir3d::GameConfig::Server_Type()))
#else
			if (!(mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::gate == mir3d::GameConfig::Server_Type()))
#endif
			{
				if (true == GetReconnectComplete() || (false == GetSendChannelInitializeComplete() && true == GetServerInitilizeComplete()))
				{
					SendChannelCreateInfo();
					SERVER_LOG(eServerLogType::eWarning, "CRpcManager::Update()::SendChannelCreateInfo() called.");

#ifdef _USE_WORLD_GAME	
					if (mir3d::mrpce_server_type::world_game == mir3d::GameConfig::Server_Type())
					{

					}
#endif
				}
			}
	}
	}

	void CRpcManager::UpdateRpcInfo(CRpc* const observer, const uint64_t& current_time)
	{
		if (UPDATE_RPCINFO_TIME <= current_time - _update_rpcinfo_time)
		{
			_update_rpcinfo_time = current_time;

			// server state 
			auto info = _update_redis_serverinfo_cs.alloc_info()->alloc_service_info();
			info->state = true == GetServerInitilizeComplete() ? 1 : 0;

			auto rpcinfo = _update_redis_serverinfo_cs.alloc_info()->alloc_rpc_info();

			rpcinfo->state = info->state;
			rpcinfo->svn_revision_number = info->svn_revision_number;
			rpcinfo->version_number = info->version_number;
			rpcinfo->table_version_number = info->table_version_number;
			rpcinfo->rpc_session_info.clear();
			GetRpcList(rpcinfo->rpc_session_info);

			rpcinfo->user_cnt = userManager.GetUserCount();
			// Web Daemon 추가로 필요
			{
				if (!(mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_community == mir3d::GameConfig::Server_Type()))
				{
					rpcinfo->connected_socket_size = networkManager.GetConnectedSocketSize();
					rpcinfo->ghost_socket_size = networkManager.GetWaitingSocketSize();
				}

				rpcinfo->max_socket_size = mir3d::GameConfig::Network_MaxSession();				
				rpcinfo->session_user_cnt = rpcinfo->user_cnt;
				rpcinfo->waiting_seesion_pool_size = SessionWaitPool::GetWaitingSeesionPoolSize();
				rpcinfo->disconnect_seesion_pool_size = 0;	// SessionWaitPool::GetDisconnectSeesionPoolSize();
			}

			auto packet = std::make_shared<CSocketWriteBuffer>();
			if (nullptr != packet->buffer)
			{
				protocol::SerializeType(packet->buffer, &_update_redis_serverinfo_cs);

				if (packet->buffer->IsError())
				{
					SERVER_LOG(eServerLogType::eWarning, "protocol::Serialize() return false, CRpcManager::Update() cmd : [%d], size : [%d]", packet->buffer->GetSerializeCommand(), packet->buffer->GetErrorSerializeSize());
				}
				else
				{
					observer->Send(packet);
				}
			}
		}
	}
	
	void CRpcManager::UpdateContentsInfo(const uint64_t& current_time)
	{

	}

	void CRpcManager::UpdateRpcHeartbeat(const uint64_t& current_time)
	{
		// heartbeat socket
		if (mir3d::NetworkConfig::GetRpcSocketHeartbeat())
		{
			if (mir3d::NetworkConfig::GetRpcSocketHeartbeatKeepAliveInterval() < (current_time - _update_rpc_heartbeat_time))
			{
				_update_rpc_heartbeat_time = current_time;

				std::lock_guard<std::mutex> lock(_mutex_socket_heartbeat);
				for (auto item : _map_socket_heartbeat)
				{
					auto rpc = item.second;
					if (nullptr != rpc)
					{

						// SERVER_LOG(eServerLogType::eFatal, "RcpHeartbeatSend().UpdateRpcHeartbeat() full tag : %s, %s", rpc->GetFullTag().c_str(), rpc->GetRemoteInfo().c_str());

						
						if (mir3d::NetworkConfig::GetRpcSocketHeartbeatRetryLimitCount() < rpc->GetHeartbeatCheckCount())
						{
							// rpc->ForceDisconnect();
							// 2023.07.25 gogoblue74 RPC heartbeat 체크시 disconnect가 없어서 계속 로그만 찍는다. 초기화 하고 다시 해보는 걸로..
							rpc->SetHeartbeatCheckCount(true);	
							SERVER_LOG(eServerLogType::eWarning, "RcpHeartbeatSend().ForceDisconnect() %s, check count : %d", rpc->GetRemoteInfo().c_str(), rpc->GetHeartbeatCheckCount());
						}
						else
						{
							auto packet = std::make_shared<CSocketWriteBuffer>();
							if (nullptr != packet->buffer)
							{
								mir3d::mrpc_heartbeat_check_cs cs;
								cs.uid = rpc->GetHeartbeatUid();
								cs.param = current_time;

								protocol::SerializeType(packet->buffer, &cs);

								rpc->Send(packet);

								rpc->SetHeartbeatCheckCount(false);
							}
						}
					}
				}
			}
		}
	}

	void CRpcManager::PrintRpcInfo(void)
	{
		SERVER_LOG(eServerLogType::eInfo, "CRpcManager rpc mange info");

		mrpc_update_debug_print_rpcinfo_cs cs;
	
		cs.gid = GameConfig::Server_Gid();

		auto managed_rpc_info = cs.alloc_info();
		managed_rpc_info->name.assign(_rpc_fulltag_string);
		
		{	
			std::lock_guard<std::mutex> lock(_mutex_tryconnet);

			SERVER_LOG(eServerLogType::eInfo, "_map_tryconnet info, count : %d", _map_tryconnet.size());
			
			mrpcs_managed_rpc_info info;
			info.name = "_map_tryconnet";

			for (auto iter : _map_tryconnet)
			{					
				mrpcs_managed_rpc item;
				
				std::ostringstream os;

				// os << iter.first << ", type : " << mir3d::SERVER_TAG_NAME[static_cast<int32_t>(iter.second->GetType())] << ", index : " << iter.second->GetIndex();
				os << iter.first << ", type : " << iter.second->GetType() << ", index : " << iter.second->GetIndex();

				item.key = os.str();
				os.clear();

				os << iter.second->GetIp().c_str() << ":" << iter.second->GetPort();
				item.info = os.str();

				SERVER_LOG(eServerLogType::eInfo, "\t%s, ip : %s", item.key.c_str(), item.info.c_str());

				info.list.emplace_back(item);
			}

			managed_rpc_info->info.emplace_back(info);
		}

		{
			std::lock_guard<std::mutex> lock(_mutex_maintag);

			SERVER_LOG(eServerLogType::eInfo, "_map_maintag info, count : %d", _map_maintag.size());

			mrpcs_managed_rpc_info info;
			info.name = "_map_maintag";

			for (auto iter : _map_maintag)
			{
				std::stringstream server_name;
				server_name << iter.first;

				// SERVER_LOG(eServerLogType::eInfo, "\ttype : %s, list count : %d", mir3d::SERVER_TAG_NAME[static_cast<int32_t>(iter.first)].c_str(), iter.second.size());
				SERVER_LOG(eServerLogType::eInfo, "\ttype : %s, list count : %d", server_name.str().c_str(), iter.second.size());

				for (auto item : iter.second)
				{
					mrpcs_managed_rpc item_rpc;

					std::ostringstream os;

					os << "type : " << item->GetType() << ", index : " << item->GetIndex() << ", ";
					item_rpc.key = os.str();
					os.clear();

					os << item->GetIp().c_str()  << ":" << item->GetPort();
					item_rpc.info = os.str();

					SERVER_LOG(eServerLogType::eInfo, "\t%s, ip : %s", item_rpc.key.c_str(), item_rpc.info.c_str());

					info.list.emplace_back(item_rpc);
				}
			}

			managed_rpc_info->info.emplace_back(info);
		}

		{
			std::lock_guard<std::mutex> lock(_mutex_fulltag);

			SERVER_LOG(eServerLogType::eInfo, "_map_fulltag info, count : %d", _map_fulltag.size());
			
			mrpcs_managed_rpc_info info;
			info.name = "_map_fulltag";

			for (auto iter : _map_fulltag)
			{
				mrpcs_managed_rpc item;

				std::ostringstream os;

				os << iter.first << ", type : " << iter.second->GetType() << ", index : " << iter.second->GetIndex() << ", ";
				item.key = os.str();
				os.clear();

				os << iter.second->GetIp().c_str() << ":" << iter.second->GetPort();
				item.info = os.str();

				SERVER_LOG(eServerLogType::eInfo, "\t%s, ip : %s", item.key.c_str(), item.info.c_str());

				info.list.emplace_back(item);
			}

			managed_rpc_info->info.emplace_back(info);
		}

		{
			std::lock_guard<std::mutex> lock(_mutex_socket);

			SERVER_LOG(eServerLogType::eInfo, "_map_socket info, count : %d", _map_socket.size());

			mrpcs_managed_rpc_info info;
			info.name = "_map_socket";

			for (auto iter : _map_socket)
			{				
				auto session = iter.first->GetSession();

				mrpcs_managed_rpc item;

				std::ostringstream os;
				
				if (nullptr != session)
				{
					os << "socket id : " << iter.first->GetID() << ", session id : " << session->GetID() << ", type : " << iter.second->GetType() << ", index : " << iter.second->GetIndex() << ", ";
					item.key = os.str();
					os.clear();

					os << iter.second->GetIp().c_str() << ":" << iter.second->GetPort();
					item.info = os.str();

					SERVER_LOG(eServerLogType::eInfo, "\t%s, ip : %s", item.key.c_str(), item.info.c_str());
				}
				else
				{
					os << "socket id : " << iter.first->GetID() << ", session is null, type : " << iter.second->GetType() << ", index : " << iter.second->GetIndex();
					item.key = os.str();
					os.clear();

					os << iter.second->GetIp().c_str() << ":" << iter.second->GetPort();
					item.info = os.str();

					SERVER_LOG(eServerLogType::eInfo, "\t%s, ip : %s", item.key.c_str(), item.info.c_str());
				}

				info.list.emplace_back(item);
			}

			managed_rpc_info->info.emplace_back(info);
		}

		RpcSend(mrpce_server_type::gmobserver, cs);
	}

	void CRpcManager::OnRpcHeartbeatResponse(const int64_t& uid, const int64_t& param)
	{
		std::lock_guard<std::mutex> lock(_mutex_socket_heartbeat);
		auto iter = _map_socket_heartbeat.find(uid);

		if (_map_socket_heartbeat.end() != iter)
		{
			auto rpc = iter->second;

			if (nullptr != rpc)
			{
				auto now_tick = mir3d::util::mirTime::GetTickMilliCount();
				
				if (mir3d::NetworkConfig::GetRpcSocketHeartbeatLatencyCheckTime() < static_cast<int64_t>(now_tick) - param)
				{
					SERVER_LOG(eServerLogType::eWarning, "OnRpcHeartbeatResponse() %s, check count : %d, response time : %lld", rpc->GetRemoteInfo().c_str(), rpc->GetHeartbeatCheckCount(), now_tick - param);
				}

				rpc->SetHeartbeatCheckCount(true);
			}
		}
	}

	void CRpcManager::SendOccupationwarGameserverLog(mrpc_occupationwar_gameserver_log_sc& log)
	{
#ifdef _USE_GLOBAL_SERVICE
		RpcSend(mrpce_server_type::guildmanager, log);
#endif
	}

	//--------------------------------------------------------------------------------------------------------------------
	// acceptor
	//--------------------------------------------------------------------------------------------------------------------
	void OnGameRpcAcceptorHookHandler(packetContext* context) 
	{
		gamePacketWorker.PushSwitch(0, context);
	}
	void OnGateRpcAcceptorHookHandler(packetContext* context)
	{

	}
	void OnCommunityRpcAcceptorHookHandler(packetContext* context)
	{

	}

	void OnRpcAcceptorSocketOpened(CSocket* socket) 
	{	
		socket->SetRpc(true);

		SERVER_LOG(eServerLogType::eInfo, "OnRpcAcceptorSocketOpened() %s", socket->GetRemoteInfo().c_str());
	}

	void OnRpcAcceptorSocketClosed(CSocket* socket)
	{
		SERVER_LOG(eServerLogType::eInfo, "OnRpcAcceptorSocketClosed() %s", socket->GetRemoteInfo().c_str());
		
		rpcManager.Disconnected(socket, true);
	}

	void OnRpcAcceptorSessionOpened(CSession* session, const bool& reconnect)
	{
		// 접속된 서버의 정보를 얻는다.
		{
			mrpc_connector_rpcinfo_cs cs;
			session->Send(cs);
		}

		SERVER_LOG(eServerLogType::eInfo, "OnRpcAcceptorSessionOpened() session id : %lld", session->GetID());		
		rpcManager.ConnectedSession(session, true);
	}

	void OnRpcAcceptorSessionClosed(CSession* session) 
	{	
		SERVER_LOG(eServerLogType::eInfo, "OnRpcAcceptorSessionClosed() session id : %lld", session->GetID());
	}

	//--------------------------------------------------------------------------------------------------------------------
	// connector
	//--------------------------------------------------------------------------------------------------------------------
	void OnGameRpcConnectorHookHandler(packetContext* context) 
	{	
		gamePacketWorker.PushSwitch(static_cast<int32_t>(MakeRpcPacketTag(context->buffer)), context);

#ifdef _DELETE
		switch (static_cast<mpe_rpc_cmd>(context->cmd))
		{
		case mpe_rpc_cmd::contents_onoff_update_cs:
		{
			int index_count = mir3d::GameConfig::Server_ThreadCount();
			std::unordered_map<int, packetContext*> packet_list;

			for (int i = 0; i < index_count; ++i)
			{
				if (i == 0)
				{
					packet_list.emplace(i, context);
				}
				else
				{
					auto context_cpy = PacketContextPool::Pop();

					context_cpy->cmd = context->cmd;
					context_cpy->session_id = context->session_id;
					context_cpy->size = context->size;
					//context_cpy->zone_tag = context->zone_tag;
					context_cpy->socket = context->socket;
					context_cpy->pop_time = util::mirTime::GetTickMilliCount();

					memcpy(context_cpy->buffer, context->buffer, context->size);

					packet_list.emplace(i, context_cpy);
				}
			}

			for (auto itr = packet_list.begin(); itr != packet_list.end(); ++itr)
			{
				gamePacketWorker.PushSwitch(itr->first, itr->second);
			}
		}
		break;
		default:
		{
			int32_t tag = static_cast<int32_t>(MakeRpcPacketTag(context->buffer));
			gamePacketWorker.PushSwitch(tag, context);
		}
		break;
		}
#endif
	}
	void OnGateRpcConnectorHookHandler(packetContext* context)
	{

	}
	void OnCommunityRpcConnectorHookHandler(packetContext* context)
	{

	}

	void OnRpcConnectorSocketOpened(CSocket* socket) 
	{
		socket->SetRpc(true);

		SERVER_LOG(eServerLogType::eInfo, "OnRpcConnectorSocketOpened() %s", socket->GetRemoteInfo().c_str());

		rpcManager.Connected(socket);
	}

	void OnRpcConnectorSocketConnectFaild(CSocket* socket)
	{
		SERVER_LOG(eServerLogType::eInfo, "OnRpcConnectorSocketConnectFaild() socket id : %d, %s", socket->GetID(), socket->GetRemoteInfo().c_str());
		rpcManager.ConnectFailed(socket);
	}

	void OnRpcConnectorSocketClosed(CSocket* socket)
	{
		SERVER_LOG(eServerLogType::eInfo, "OnRpcConnectorSocketClosed() socket id : %d", socket->GetID());

		// 소켓이 정리 되기전에 세션이 정리되어야 정상 처리된다.
		//rpcManager.DisconnectedSession(socket->GetSession());

		rpcManager.Disconnected(socket);
	}

	void OnRpcConnectorSessionOpened(CSession* session, const bool& reconnect)
	{
		SERVER_LOG(eServerLogType::eInfo, "OnRpcConnectorSessionOpened() session id : %lld", session->GetID());

		rpcManager.ConnectedSession(session);
	}

	void OnRpcConnectorSessionClosed(CSession* session) 
	{
		SERVER_LOG(eServerLogType::eInfo, "OnRpcConnectorSessionClosed() session id : %lld", session->GetID());

		rpcManager.DisconnectedSession(session);
	}

	void CRpcManager::SetCommunityZoneInitialize(void)
	{
		_community_zone_initialize = true;
	}

	void CRpcManager::SetServerInitilizeComplete(bool complete)
	{
		std::lock_guard<std::mutex> lock(_mutex_init);
		_server_initilize_complete = complete;
	}

	bool CRpcManager::GetServerInitilizeComplete()
	{
		std::lock_guard<std::mutex> lock(_mutex_init);
		return _server_initilize_complete;
	}

	void CRpcManager::SetServerInfoComplete(bool complete)
	{
		std::lock_guard<std::mutex> lock(_mutex_server_info);
		_server_info_complete = complete;
	}

	bool CRpcManager::GetServerInfoComplete()
	{
		std::lock_guard<std::mutex> lock(_mutex_server_info);
		return _server_info_complete;
	}

	void CRpcManager::SetSendChannelUpdate(bool send)
	{
		std::lock_guard<std::mutex> lock(_mutex_send_channel_update);
		_send_channel_update = send;
	}

	bool CRpcManager::GetSendChannelUpdate()
	{
		std::lock_guard<std::mutex> lock(_mutex_send_channel_update);
		return _send_channel_update;
	}

	void CRpcManager::SetChannelInitializeComplete(bool send)
	{
		std::lock_guard<std::mutex> lock(_mutex_channel_initialize_complate);
		_channel_initialize_complate = send;
	}

	bool CRpcManager::GetSendChannelInitializeComplete()
	{
		std::lock_guard<std::mutex> lock(_mutex_channel_initialize_complate);
		return _channel_initialize_complate;
	}

	void CRpcManager::SetReconnectComplete(bool send)
	{
		std::lock_guard<std::mutex> lock(_mutex_reconnect_complete);
		_reconnect_complete = (GetSendChannelInitializeComplete() && send);
	}

	bool CRpcManager::GetReconnectComplete()
	{
		std::lock_guard<std::mutex> lock(_mutex_reconnect_complete);
		return _reconnect_complete;
	}
}	// namespace mir3d