#pragma once

#include "gameEventWorker.h"
#include "gamePacketWorker.h"
#include "networkManager.h"
#include "userManager.h"
#include "rpcManager.h"

namespace mir3d
{
	class CMir3dGame
	{
	public:
		CMir3dGame() = default;
		~CMir3dGame() = default;

	public:
		bool Initialize(void);
		void Destroy(void);

		bool Start(void);

		void WaitCommand(void);
		void WaitKeyHit(void);

	private:
		bool Initialize_Config(void);
		bool Initialize_Loger(const std::string& base_path, const int minloglevel = 0, const bool write_file = true, const bool print_console = true);
		bool Initialize_Dump(void);		
		bool Initialize_Network(void);
		bool Initialize_Observer(void);
		bool Initialize_Logserver(void);
		bool Initialize_TableManager(void);

		bool PreInitialize_Manager(void);
		bool Initialize_Manager(void);	
		bool Initialize_Community(void);

	private:
		mir3d::CWaitForShutdown			_wait_for_shutdown;
		mir3d::util::CUidGenerate		_uid_Generate;
		mir3d::CUserManager				_user_manager;
		mir3d::CProfileManager			_profile_manager;

	private:
		mir3d::CNetworkManager*			_networkManager = nullptr;
		mir3d::CSerializeBufferPool*	_serializeBufferPool = nullptr;
		mir3d::CGameEventWorker*		_gameEventWorker = nullptr;
		mir3d::CGamePacketWorker*		_gamePacketWorker = nullptr;
		mir3d::CRpcManager*				_rpcManager = nullptr;

		mir3d::CServerlogManager*		_serverlogManager = nullptr;
#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
		mir3d::CNetworkController*		_networkController = nullptr;
#endif

	private:
		std::string					_base_path;
		std::string					_data_path;

	private:
		CMir3dGame(const CMir3dGame&) = delete;
		CMir3dGame& operator=(const CMir3dGame&) = delete;
		CMir3dGame(CMir3dGame&&) = delete;
		CMir3dGame& operator=(CMir3dGame&&) = delete;
	};

}	// namespace mir3d

