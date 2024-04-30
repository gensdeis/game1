// utf-8 으로 저장해야함
#include "stdafx_net.h"
#include "networkController.h"
#include <common/config.h>
#include <common/serverlogManager.h>
#include <protocol/mrpc_player_connect_info.h>
#include <protocol/mrpc_game_duplicate_login.h>
//#include <../game/rpcManager.h>

namespace mir3d
{
	void CNetworkObject::Initialize(const int64_t& access_token, const int32_t& gid, const int64_t& auid, const int64_t& cuid)
	{
		_access_token = access_token;
		_gid = gid;
		_auid = auid;
		_cuid = cuid;
		_hash_index = _auid % AUID_HASH_COUNT;

		SetStepIndex(1);

		_socket = nullptr;
	}

	void CNetworkObject::Reset(bool reuse)
	{
		if (false == reuse)
		{
			_access_token = 0;
			_gid = 0;
			_auid = 0;
			_cuid = 0;
			_hash_index = 0;
		}

		if (nullptr != _socket)
		{
			_socket->SetCompletedAuthentication(false);
			_socket = nullptr;
		}

		_step_index = 0;
	}

	void CNetworkObject::Reset(const int32_t& gid, const int64_t& cuid)
	{
		_gid = gid;
		_cuid = cuid;
	}

	void CNetworkObject::SetDuplicate(bool reuse, const char* func_name)
	{
		if (nullptr != _socket)
		{
			if (mir3d::mrpce_server_type::gate != mir3d::GameConfig::Server_Type())
			{
				_socket->SendErrorMessage(mpe_error::duplicate_login_retry, mpe_cmd::game_login_sc);
				_socket->ForceDisconnect(func_name, false, true);		// 중복로그인 메시지를 보낸 후 socket close를 하기 위해서 post_close_socket false 로
			}
			else
			{
				_socket->ForceDisconnect(func_name, true, false);
			}
		}

		Reset(reuse);
	}

	void CNetworkObject::SetAccessToken(const int64_t& access_token, const char* func_name)
	{
#ifdef _DEBUG
		SERVER_LOG(eServerLogType::eDebug, "SetAccessToken() change access_token : %lld -> %lld, call func : %s", _access_token, access_token, func_name);
#endif
		_access_token = access_token;
	}

	void CNetworkController::Initialize(void)
	{
		_list_map_network.reserve(AUID_HASH_COUNT);
		_list_mutex.reserve(AUID_HASH_COUNT);
		_list_pool.reserve(AUID_HASH_COUNT);

		for (int32_t i = 0; i < AUID_HASH_COUNT; i++)
		{
			_list_map_network.push_back(new std::unordered_map<int64_t, CNetworkObject*>());
			_list_mutex.push_back(new std::mutex());
			_list_pool.push_back(new CMemPool<CNetworkObject>(1024, 4, "CNetworkController.CNetworkObject()", OnMempoolAllocLogger));
		}
	}
		
	void CNetworkController::SetConnectionWait(const char* func_name, const int64_t& access_token, const int32_t& gid, const int64_t& auid, const int64_t& cuid, const bool reconnect, const bool force_insert)
	{
		int32_t hash_index = auid % AUID_HASH_COUNT;

		std::lock_guard<std::mutex> lock(*_list_mutex[hash_index]);
		{
			CNetworkObject* networkObject = nullptr;

			// 기존에 있는지 찾아 봐서, 있으면 force close 시켜버린다.
			auto iter = _list_map_network[hash_index]->find(auid);
			if (_list_map_network[hash_index]->end() != iter)
			{
				networkObject = iter->second;

				if (networkObject->GetAccessToken() != access_token)
				{
					if (mir3d::mrpce_server_type::gate == mir3d::GameConfig::Server_Type())
					{
						// client -> mp_session_auth_cs -> CSocket::SetSession()
						if (0 == cuid)
						{
#ifdef _DEBUG
							SERVER_LOG(eServerLogType::eDebug, "SetConnectionWait(gate) call func [%s]. ForceDisconnect() and change access_token. access_token : %lld => %lld, auid : %lld, cuid : %lld", func_name, networkObject->GetAccessToken(), access_token, auid, cuid);
#endif
							// 기존 연결 disconnect, 기존 정보 사용
							networkObject->SetDuplicate(true, func_name);

							// 2023.05.20 gogoblue74
							// 05.16 gate 적용 후 접속 안되는 문제를 확인하기 위해 수정한다.
							// 만약 여기 들어오면 _step_index = 0  이 되기 때문에 SetSocket() 이 안된다.
							// 일단 이렇게하고 log 보고 정리한다.
							networkObject->SetStepIndex(1);
						}
						// lobby -> gm server -> gm observer -> broardcast
						else
						{
							// 캐릭터 선택해서 들어온거다.
							networkObject->Reset(gid, cuid);
						}
					}
					else
					{
						// 정보가 있으면 기존 소켓 정리만 하고 access token 변경
						if (false == reconnect)
						{
#ifdef _DEBUG
							SERVER_LOG(eServerLogType::eDebug, "SetConnectionWait(0) call func [%s]. ForceDisconnect() and change access_token. access_token : %lld => %lld, auid : %lld, cuid : %lld", func_name, networkObject->GetAccessToken(), access_token, auid, cuid);
#endif
							networkObject->SetDuplicate(true, func_name);

							// 캐릭터 선택해서 들어온거다.
							// 강제 셋팅한다.
							networkObject->Reset(gid, cuid);
						}
						else
						{
#ifdef _DEBUG
							SERVER_LOG(eServerLogType::eDebug, "SetConnectionWait(0) call func [%s]. reconnect. and change access_token. access_token : %lld => %lld, auid : %lld, cuid : %lld", func_name, networkObject->GetAccessToken(), access_token, auid, cuid);
#endif
							// reconnect 처리다.
							// access_token 만 변경한다.
						}

						networkObject->SetStepIndex(1);
					}

					networkObject->SetAccessToken(access_token, __func__);
				}
				else
				{
#ifdef _DEBUG
					SERVER_LOG(eServerLogType::eDebug, "SetConnectionWait(1) call func [%s]. access_token eq,  access_token : %lld, auid : %lld, cuid : %lld", func_name, access_token, auid, cuid);
#endif

					if (0 <= networkObject->GetSocketIndex())
					{
						// 2023.05.10 gogoblue74
						// local 에서 테스트스 lobby / gm observer 중복으로 오게 된다. 상관읎다.
						// 개발 단계의 디버깅에서 같은 서버에서 패킷 전송이 되므로
						// 라이브 상황 또는 장비 분리가 되어 있으면 오지 않는다.
						if (mir3d::mrpce_server_type::world_game == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_indun == mir3d::GameConfig::Server_Type())
						{
							networkObject->Reset(gid, cuid);
						}
						else
						{
							if (false == force_insert)
							{
								networkObject->SetDuplicate(false, func_name);
							}
						}
					}
				}
			}
			else
			{
				networkObject = _list_pool[hash_index]->Pop();
				networkObject->Initialize(access_token, gid, auid, cuid);

				_list_map_network[hash_index]->insert(std::make_pair(auid, networkObject));
#ifdef _DEBUG
				SERVER_LOG(eServerLogType::eDebug, "SetConnectionWait() call func [%s]. insert().  access_token : %lld, auid : %lld, cuid : %lld", func_name, access_token, auid, cuid);
#endif 
			}
		}
	}

		// 클라이언트가 접속했다. 소켓 연결하고 다른 서버는 정보 삭제 시킨다.
	bool CNetworkController::SetSocket(const int64_t& auid, CSocket* const socket, int64_t& access_token)
	{
		int32_t hash_index = auid % AUID_HASH_COUNT;
		CNetworkObject* networkObject = nullptr;
		bool result = false;
		int32_t gid = 0;

		std::lock_guard<std::mutex> lock(*_list_mutex[hash_index]);
		{
			auto iter = _list_map_network[hash_index]->find(auid);
			if (_list_map_network[hash_index]->end() != iter)
			{
				networkObject = iter->second;

				//  lobby 에서 받아 셋팅 되어 있다.  socket 정보가 다르면 끊어 버린다.
				if (0 < networkObject->GetSocketIndex())
				{
					if (networkObject->GetSocketIndex() != socket->GetID())
					{
#ifdef _DEBUG
						SERVER_LOG(eServerLogType::eDebug, "mp_session_auth_cs(0), access_token : % lld = > % lld, auid : % lld", networkObject->GetAccessToken(), auid);
#endif
						// 이전 접속은 종료 처리
						networkObject->SetDuplicate(false, __func__);
					}
				}
				// 다시 셋팅 (redirect .... )
				else
				{
					if (-1 == networkObject->GetSocketIndex() && 0 < networkObject->GetAccessToken() && 1 == networkObject->GetStepIndex())
					{
						networkObject->SetSocket(socket, __func__);
						access_token = networkObject->GetAccessToken();
						result = true;
						gid = networkObject->GetGid();
#ifdef _DEBUG
						SERVER_LOG(eServerLogType::eDebug, "mp_session_auth_cs(1) my socket, access_token : % lld, auid : % lld", networkObject->GetAccessToken(), auid);
#endif
					}
				}
			}
			else
			{
#ifdef _DEBUG
				SERVER_LOG(eServerLogType::eDebug, "mp_session_auth_cs(2) not found info. auid : %lld", auid);
#endif
			}
		}

		// 전체로 전송해서 삭제 시킨다.
		if (true == result)
		{
			if (!(mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::gate == mir3d::GameConfig::Server_Type()))
			{
				mrpc_player_connect_info_sc sc;
				sc.flag = 0;
				sc.auid = auid;
				sc.cuid = networkObject->GetCuid();
				sc.gid = gid;
				sc.access_token = networkObject->GetAccessToken();

#ifdef _DEBUG
				SERVER_LOG(eServerLogType::eDebug, "mrpc_player_connect_info_sc() send. access_token : %lld, auid : %lld, cuid : %lld, flag : %d", sc.access_token, sc.auid, sc.cuid, sc.flag);
#endif

				// 2023.05.05 gogoblue74 ZoneEnterProcess() 기능이 있어 access_token 변경 작업을 안해도 된다.
				// observer 에 전송 할 수 없다. 
				if (mir3d::mrpce_server_type::world_game == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_indun == mir3d::GameConfig::Server_Type())
				{
					BroadcastDuplicatePacket(sc, false, true);
				}
				else
				{
					BroadcastDuplicatePacket(sc, true);
				}
			}
		}

		return result;
	}

	void CNetworkController::DisconnectSocket(const char* func_name, const int64_t& auid, const bool& force_close, const bool& release_close, const int64_t& access_token)
	{
		int32_t hash_index = auid % AUID_HASH_COUNT;

		std::lock_guard<std::mutex> lock(*_list_mutex[hash_index]);
		{
			CNetworkObject* networkObject = nullptr;

			auto iter = _list_map_network[hash_index]->find(auid);
			if (_list_map_network[hash_index]->end() != iter)
			{
				networkObject = iter->second;

				if (true == release_close)
				{
					_list_pool[hash_index]->Push(iter->second);
					_list_map_network[hash_index]->erase(auid);

#ifdef _DEBUG
					SERVER_LOG(eServerLogType::eDebug, "DisconnectSocket() access_token eq erase. call func : %s. access_token : %lld, auid : %lld", func_name, access_token, auid);
#endif
				}
				else  if (true == force_close)
				{
					networkObject->SetDuplicate(false, func_name);

					_list_pool[hash_index]->Push(iter->second);
					_list_map_network[hash_index]->erase(auid);

				}
				else
				{
					// 기존에 있던 소켓 Release() 처리시 정리
					if (networkObject->GetAccessToken() == access_token)
					{
						networkObject->Reset(false);

						_list_pool[hash_index]->Push(iter->second);
						_list_map_network[hash_index]->erase(auid);
					}
					else
					{
#ifdef _DEBUG
						SERVER_LOG(eServerLogType::eDebug, "DisconnectSocket(2) not found erase. call func : %s. access_token : %lld, auid : %lld", func_name, access_token, auid);
#endif
					}
				}
			}
		}
	}

	void CNetworkController::ZoneEnterProcess(const int64_t& auid, const int32_t& socket_id, const char* func_name)
	{
		int32_t hash_index = auid % AUID_HASH_COUNT;
		// bool result = false;
		CNetworkObject* networkObject = nullptr;

		std::lock_guard<std::mutex> lock(*_list_mutex[hash_index]);
		{
			auto iter = _list_map_network[hash_index]->find(auid);
			if (_list_map_network[hash_index]->end() != iter)
			{
				networkObject = iter->second;

				if (networkObject->GetSocketIndex() != socket_id)
				{
					networkObject->SetDuplicate(false, __func__);

					_list_pool[hash_index]->Push(iter->second);
					_list_map_network[hash_index]->erase(auid);
				}

				// result = true;

#ifdef _DEBUG		
				SERVER_LOG(eServerLogType::eDebug, "ZoneEnterProcess() my socket, access_token : %lld, auid : %lld, call func : %s", networkObject->GetAccessToken(), auid, func_name);
#endif
			}
			else
			{
#ifdef _DEBUG
				SERVER_LOG(eServerLogType::eDebug, "ZoneEnterProcess() not found info. auid : %lld, call func : %s", auid, func_name);
#endif
			}
		}

		// 전체로 전송해서 삭제 시킨다.
		// 2023.03.19 gogoblue74 무조건 
		// if (true == result)
		{
			if (!(mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::gate == mir3d::GameConfig::Server_Type()))
			{
				mrpc_game_duplicate_login_sc sc;
				sc.auid = auid;
				sc.access_token = 0;	// networkObject->GetAccessToken();
				sc.type = 2;

#ifdef _DEBUG
				SERVER_LOG(eServerLogType::eDebug, "ZoneEnterProcess() mrpc_game_duplicate_login_sc() send. auid : %lld, call func : %s", auid, func_name);
#endif

				BroadcastDuplicatePacket(sc, false);
			}
		}
	}

	int32_t CNetworkController::GetGid(const int64_t& auid)
	{
		int32_t hash_index = auid % AUID_HASH_COUNT;

		std::lock_guard<std::mutex> lock(*_list_mutex[hash_index]);
		{
			auto iter = _list_map_network[hash_index]->find(auid);
			if (_list_map_network[hash_index]->end() != iter)
			{
				return iter->second->GetGid();
			}
		}

		return 0;
	}

	int64_t CNetworkController::GetCuid(const int64_t& auid)
	{
		int32_t hash_index = auid % AUID_HASH_COUNT;

		std::lock_guard<std::mutex> lock(*_list_mutex[hash_index]);
		{
			auto iter = _list_map_network[hash_index]->find(auid);
			if (_list_map_network[hash_index]->end() != iter)
			{
				return iter->second->GetCuid();
			}
		}

		return 0;
	}
} // namespace mir3d
