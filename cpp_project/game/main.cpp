#include "stdafx.h"
#include "main.h"
#include <common/dump.h>

#ifdef _WINDOWS
#include <crtdbg.h>
#include <conio.h>
#include <timeapi.h>
#pragma comment(lib, "winmm.lib")
#endif

#ifdef _TP_USAGE
using namespace concurrency;
#endif

int main()
{
#ifdef _WINDOWS
	DWORD mode = 0x0;

	GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);
	
	// remove flag
	mode &= ~ENABLE_PROCESSED_INPUT;
	mode &= ~ENABLE_QUICK_EDIT_MODE;

	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), mode);

	timeBeginPeriod(1);
#endif 
	mir3d::CMir3dGame mir3dGame;
	
	if (false == mir3dGame.Initialize())
		goto terminate;
		
	if (false == mir3dGame.Start())
		goto terminate;

terminate:
#ifdef _WINDOWS
	timeEndPeriod(10);	
#endif
	
	mir3dGame.Destroy();

	return 0;
}

bool mir3d::CMir3dGame::Initialize(void)
{
	_base_path = boost::filesystem::current_path().string();
	_data_path = _base_path + DIRECTORY_SEPARATOR_STRING + "data";

	if (false == Initialize_Config())		return false;	
	if (false == Initialize_Dump())			return false;	
	if (false == Initialize_Network())		return false;	
	if (false == Initialize_Observer())		return false;
	if (false == Initialize_Logserver())	return false;
	if (false == Initialize_TableManager())	return false;
	if (false == PreInitialize_Manager())	return false;

	return true;
}

void mir3d::CMir3dGame::Destroy(void)
{
	if (nullptr != _rpcManager)
	{
		_rpcManager->Destroy();
	}

	if (nullptr != _networkManager)
	{
		_networkManager->Destroy();
	}

	if (nullptr != _gameEventWorker)
	{
		_gameEventWorker->Destroy();
	}

	if (nullptr != _gamePacketWorker)
	{
		_gamePacketWorker->Destroy();
	}

	mir3d::Network::Destroy();

	SAFE_DELETE(_networkManager);	
	SAFE_DELETE(_gameEventWorker);
	SAFE_DELETE(_gamePacketWorker);
	SAFE_DELETE(_rpcManager);

	SAFE_DELETE(_serializeBufferPool);	
#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
	SAFE_DELETE(_networkController);
#endif

	if (nullptr != _serverlogManager)
	{
		_serverlogManager->Destroy();
	}

	SAFE_DELETE(_serverlogManager);
}

bool mir3d::CMir3dGame::Start(void)
{
	_networkManager->Initialize();

#ifdef _USE_WORLD_GAME	
	if (mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_community == mir3d::GameConfig::Server_Type())
#else
	if (mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type())
#endif
	{
		if (false == Initialize_Community())
			return false;
	}
	else
	{
		_gameEventWorker->Initialize();

		if (false == Initialize_Manager())
			return false;

		_gameEventWorker->Start();
	}
	
	_networkManager->Start();

	_rpcManager->SetServerInitilizeComplete(true);

	GameConfig::SetServiceState();

	WaitKeyHit();
	return true;
}

void mir3d::CMir3dGame::WaitKeyHit()
{
#ifdef _WINDOWS

	system("cls");
	std::cout << "key : [ i(INFO), d(DEBUG), w(WARNING), s(STDOUT), n(NETWORK), r(RPC), q(QUIT), f(FileWrite) ]" << std::endl;

	while (true)
	{
		std::chrono::milliseconds dura(100);
		std::this_thread::sleep_for(dura);
		if (_kbhit())
		{
			std::future<bool> received;
			int result = -1;
			char key = _getch();

			if ('r' == key || 'R' == key)
			{
				std::cout << "press r";
				rpcManager.PrintRpcInfo();
				// break;
			}
	
			if (1 == result)
				std::cout << "ON\n";
			else if (0 == result)
				std::cout << "OFF\n";
			else if (-1 == result)
				std::cout << "This key is not set\n";
		}

		if (true == mir3d::waitForShutdown.GetShutdownFlag())
		{
			std::cout << "_shutdown_flag is true !!!\n";			
			break;
		}
	}
#endif

}

bool mir3d::CMir3dGame::Initialize_Config(void)
{
	// base config
	if (false == mir3d::GameConfig::Initialize(_data_path))
		return false;
	
	if (false == Initialize_Loger(_base_path))
		return false;

	// network config
	std::string network_config = _data_path + DIRECTORY_SEPARATOR_STRING + "config_network.json";
	if (false == mir3d::Network::Initialize(network_config, GameConfig::Server_ThreadCount()))
		return false;

	return true;
}
// bool Initialize_Loger(const std::string& base_path, const int minloglevel = 0, const bool write_file = true, const bool print_console = true);
bool mir3d::CMir3dGame::Initialize_Loger(const std::string& base_path, const int minloglevel, const bool write_file, const bool print_console)
{
	const std::string log_path = base_path + DIRECTORY_SEPARATOR_STRING + GameConfig::Server_LogPath() + DIRECTORY_SEPARATOR_STRING;
	const std::string log_path2 = base_path + DIRECTORY_SEPARATOR_STRING + GameConfig::Server_LogPath() + "2" + DIRECTORY_SEPARATOR_STRING;

	std::string log_file_base = "";

	const mrpce_server_type server_type = GameConfig::Server_Type();
	const int32_t server_gid = GameConfig::Server_Gid();
	const int32_t server_index = GameConfig::Server_Index();

	if (server_type == mrpce_server_type::game)
	{
		log_file_base += "game";
	}
	else if (server_type == mrpce_server_type::gate)
	{
		log_file_base += "gate";
	}
	else if (server_type == mrpce_server_type::indun)
	{
		log_file_base += "indun";
	}
	else if (server_type == mrpce_server_type::community)
	{
		log_file_base += "community";
	}
	else if (server_type == mrpce_server_type::world_indun)
	{
		log_file_base += "worldindun";
	}
#ifdef _USE_WORLD_GAME	
	else if (server_type == mrpce_server_type::world_game)
	{
		log_file_base += "worldgame";
	}
	else if (server_type == mrpce_server_type::world_community)
	{
		log_file_base += "worldcommunity";
	}
#endif
	else
	{
		std::cout << "invalid server type. check config.json.";
	}

	std::string revision = std::to_string(GameConfig::Version_Svn_Revision_Number());

	log_file_base += "[" + revision + "]" + std::to_string(server_gid) + "_" + std::to_string(server_index) + "_";

	/*
	auto logworker = g3::LogWorker::createLogWorker();

	//std::unique_ptr<g3::SinkHandle<CustomFileSink>> sinkhandle;
	//std::unique_ptr<g3::SinkHandle<ColorSink>> colorsinkhandle;

	if (true == write_file)
	{
		_sinkhandle = logworker->addSink(std::make_unique<mir3d::CustomFileSink>(log_file_base, log_path), &mir3d::CustomFileSink::fileWrite);
		_sinkhandle->call(&CustomFileSink::SetRotateTime, 1000*60*10).wait();
	}
		

	if (true == print_console)
		_colorsinkhandle = logworker->addSink(std::make_unique<mir3d::ColorSink>(), &mir3d::ColorSink::ReceiveLogMessage);

	g3::initializeLogging(logworker.get());
	
	_logworker = std::move(logworker);
	*/

    // if (true == mir3d::GameConfig::Actionlog_Create())
    {
        mir3d::ActionLogger::Initialize();
    }

	_serverlogManager = new mir3d::CServerlogManager(log_path, log_file_base, 1000 * 60 * 10, "server_log_manager");
	_serverlogManager->Initialize();
	_serverlogManager->Start();

	return true;
}

bool mir3d::CMir3dGame::Initialize_Dump(void)
{
#ifdef _WINDOWS 	
	if (true == mir3d::GameConfig::Dump_Create())
	{
		mir3d::Dump::Initialize();
	}
#endif

	return true;
}

bool mir3d::CMir3dGame::Initialize_Network(void)
{
	{
		const auto& poolinfo = mir3d::GameConfig::GetPoolInfo("serialize_buffer");
		if (nullptr == poolinfo)
		{
			SERVER_LOG(eServerLogType::eWarning, "main InitializeSerializeBuffer() failed.");
			return false;
		}
		_serializeBufferPool = new mir3d::CSerializeBufferPool(poolinfo->default_size, poolinfo->create_size);

		mir3d::Network::Initialize_heartbeat_pakcet();
	}

#ifdef _USE_GATE_COMMUNITY
	// gate -> community 일때는 community 는 rpc 통신만 한다.

#ifdef _USE_WORLD_GAME	
	if (!(mir3d::mrpce_server_type::community == mir3d::GameConfig::Server_Type() || mir3d::mrpce_server_type::world_community == mir3d::GameConfig::Server_Type()))
#else
	if (mir3d::mrpce_server_type::community != mir3d::GameConfig::Server_Type())
#endif

#endif
	{
		_networkManager = new mir3d::CNetworkManager(mir3d::GameConfig::Network_ListenPort(), mir3d::GameConfig::Network_MaxSession(), mir3d::GameConfig::Network_ThreadCount());
	}

	_gamePacketWorker = new mir3d::CGamePacketWorker(mir3d::GameConfig::Server_ThreadCount());
	_gameEventWorker = new mir3d::CGameEventWorker(mir3d::GameConfig::Server_EventThreadCount());

	_rpcManager = new mir3d::CRpcManager(mir3d::GameConfig::Rpc_ListenPort(), mir3d::GameConfig::Rpc_MaxSession(), mir3d::GameConfig::Rpc_ThreadCount(), mir3d::GameConfig::Rpc_UpdateSec());

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
	_networkController = new CNetworkController();

	_networkController->Initialize();
#endif

	return true;
}

bool mir3d::CMir3dGame::Initialize_Observer(void)
{
	_gamePacketWorker->Initialize();

	_rpcManager->Initialize();

	_gamePacketWorker->Start();

	_rpcManager->Start();

	const int OBSERVER_CONNECT_CHECKTIME = 1;
	const int OBSERVER_CONNECT_TIMEOUT = 60000;

	std::chrono::seconds duration(OBSERVER_CONNECT_CHECKTIME);
	uint64_t start_time = mir3d::util::mirTime::GetTickMilliCount();

	while (true)
	{
		std::this_thread::sleep_for(duration);

		if (mir3d::rpcManager.ConnectedObserver())
		{
			if (mrpce_server_type::community == GameConfig::Server_Type()		|| 
				mrpce_server_type::world_community == GameConfig::Server_Type() ||
				mrpce_server_type::world_indun == GameConfig::Server_Type()		||
				mrpce_server_type::gate == GameConfig::Server_Type()			|| 
				mir3d::rpcManager.GetServerInfoComplete())
			{
				break;
			}
		}

		if ((OBSERVER_CONNECT_TIMEOUT) < mir3d::util::mirTime::GetTickMilliCount() - start_time)
		{
			SERVER_LOG(eServerLogType::eWarning, "observer connect time out.");
			return false;
		}
	}

	return true;
}

bool mir3d::CMir3dGame::Initialize_Logserver(void)
{
	return true;
}

bool mir3d::CMir3dGame::Initialize_TableManager(void)
{
	return true;
}

bool mir3d::CMir3dGame::PreInitialize_Manager(void)
{
	if (false == mir3d::util::uidGenerate.Initialize(mir3d::GameConfig::Server_Gid(), mir3d::GameConfig::Server_Index()))
	{
		SERVER_LOG(eServerLogType::eWarning, "util::uidGenerate.Initialize() failed.");
		return false;
	}

	// dhlee : mirTime 초기화 시 컨피그 설정 참조 하도록 수정
	if (false == mir3d::util::mirTime::Initialize(GameConfig::Server_TimeZone()))
	{
		SERVER_LOG(eServerLogType::eWarning, "util::mirTime.Initialize() failed.");
		return false;
	}

	return true;
}

bool mir3d::CMir3dGame::Initialize_Manager(void)
{
	if (false == mir3d::userManager.Initialize(mir3d::GameConfig::Game_MaxPlayUser(), 32))
	{
		SERVER_LOG(eServerLogType::eWarning, "userManager.Initialize() failed.");
		return false;
	}

	return true;
}

bool mir3d::CMir3dGame::Initialize_Community(void)
{
	return true;
}