#pragma once

// utf-8 으로 저장해야함
#include "socket.h"
#include "../game/rpcManager.h"

namespace mir3d
{
	const static int32_t AUID_HASH_COUNT = 10;

	class CNetworkObject
	{
	public:
		CNetworkObject() = default;
		~CNetworkObject() = default;

	public:
		void Initialize(const int64_t& access_token, const int32_t& gid, const int64_t& auid, const int64_t& cuid);
		void Reset(bool reuse);
		void Reset(const int32_t& gid, const int64_t& cuid);
		void SetDuplicate(bool reuse, const char* func_name);

		inline void SetSocket(CSocket* const socket, const char* func_name)		{ _socket = socket; }
		inline void SetStepIndex(const int32_t& index)							{ _step_index = index; }
		inline int32_t GetStepIndex(void)										{ return _step_index; }
		inline int32_t GetSocketIndex()											
		{
			if (nullptr != _socket)
			{
				return _socket->GetID();
			}
			return -1;
		}

		inline int32_t GetHashIndex(void)										{ return _hash_index; }
		inline int32_t GetGid(void)												{ return _gid; }
		inline int64_t GetAuid(void)											{ return _auid; }
		inline int64_t GetCuid(void)											{ return _cuid; }
		inline int64_t GetAccessToken(void)										{ return _access_token; }
		inline const char* GetSocketRemoteInfo(void)							{ return nullptr != _socket ? _socket->GetRemoteInfo().c_str() : ""; }

		void SetAccessToken(const int64_t& access_token, const char* func_name);

	private:
		int64_t		_access_token = 0;
		int32_t		_gid = 0;
		int64_t		_auid = 0;
		int64_t		_cuid = 0;
		int32_t		_hash_index = 0;
		int32_t		_step_index = 0;	// 0 : SetConnectionWait() 전, 1 : SetConnectionWait() 후

		CSocket*	_socket = nullptr;

	private:
		CNetworkObject(const CNetworkObject&) = delete;
		CNetworkObject& operator=(const CNetworkObject&) = delete;
		CNetworkObject(CNetworkObject&&) = delete;
		CNetworkObject& operator=(CNetworkObject&&) = delete;
	};


	class CNetworkController : public CSingleton<CNetworkController>
	{
	public:
		CNetworkController() = default;
		~CNetworkController() = default;

	public:
		void Initialize(void);
		
	public:
		void SetConnectionWait(const char* func_name, const int64_t& access_token, const int32_t& gid, const int64_t& auid, const int64_t& cuid, const bool reconnect, const bool force_insert = false);

		// 클라이언트가 접속했다. 소켓 연결하고 다른 서버는 정보 삭제 시킨다.
		bool SetSocket(const int64_t& auid, CSocket* const socket, int64_t& access_token);

		void DisconnectSocket(const char* func_name, const int64_t& auid, const bool& force_close, const bool& release_close, const int64_t& access_token);

		void ZoneEnterProcess(const int64_t& auid, const int32_t& socket_id, const char* func_name);
		int32_t GetGid(const int64_t& auid);
		int64_t GetCuid(const int64_t& auid);

		template<typename T>
		void BroadcastDuplicatePacket(const T& packet, const bool& send_gmobserver, const bool& send_manager = false)
		{
			// world game manager
			if (send_manager)
			{
				auto rpc = rpcManager.GetRpc(mrpce_server_type::world_game_manager);
				if (nullptr == rpc || false == rpc->GetSession())
				{
				}
				else
				{
					rpc->Send(packet);
				}
			}

			// gm observer
			if (send_gmobserver)
			{
				auto rpc = rpcManager.GetRpc(mrpce_server_type::gmobserver);
				if (nullptr == rpc || false == rpc->GetSession())
				{
				}
				else
				{
					rpc->Send(packet);
				}
			}

			// game servers
			{
				std::vector<CRpc*> list_rpc;
				rpcManager.GetAllRpc(mrpce_server_type::game, list_rpc);
				if (0 != list_rpc.size())
				{
					for (auto rpc : list_rpc)
					{
						rpc->Send(packet);
					}
				}
			}
			// indun servers
			{
				std::vector<CRpc*> list_rpc;
				rpcManager.GetAllRpc(mrpce_server_type::indun, list_rpc);
				if (0 != list_rpc.size())
				{
					for (auto rpc : list_rpc)
					{
						rpc->Send(packet);
					}
				}
			}
			// world indun
			{
				auto rpc = rpcManager.GetRpc(mrpce_server_type::world_indun);
				if (nullptr == rpc || false == rpc->GetSession())
				{
				}
				else
				{
					rpc->Send(packet);
				}
			}
			// world game
			{
				auto rpc = rpcManager.GetRpc(mrpce_server_type::world_game);
				if (nullptr == rpc || false == rpc->GetSession())
				{
				}
				else
				{
					rpc->Send(packet);
				}
			}
		}

	private:
		std::vector<std::unordered_map<int64_t, CNetworkObject*>*>	_list_map_network;
		std::vector<std::mutex*>									_list_mutex;

		std::vector<CMemPool<CNetworkObject>*>						_list_pool;

	private:
		CNetworkController(const CNetworkController&) = delete;
		CNetworkController& operator=(const CNetworkController&) = delete;
		CNetworkController(CNetworkController&&) = delete;
		CNetworkController& operator=(CNetworkController&&) = delete;
	};

	#define networkController CNetworkController::getInstance()
} // namespace mir3d
