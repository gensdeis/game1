#include "stdafx_net.h"
#include "config.h"
#include <common/serverlogManager.h>

namespace mir3d
{
	bool									GameConfig::_initialize = false;
	std::vector<GameConfig::sPoolInfo>		GameConfig::_list_pool;

	GameConfig::sVersion					GameConfig::_version_info;
	GameConfig::sServer						GameConfig::_server_info;
	GameConfig::sGame						GameConfig::_game_info;
	GameConfig::sNetwork					GameConfig::_network_info;
	// GameConfig::sActionLog					GameConfig::_actionlog_info;
	GameConfig::sDump						GameConfig::_dump_info;
	GameConfig::sAddress					GameConfig::_observer_info;
	GameConfig::sUpdater					GameConfig::_updater;
	GameConfig::sNetwork					GameConfig::_rpc_info;
	std::vector<GameConfig::sCommunity>		GameConfig::_list_community;
	bool									GameConfig::_service_state = false;
	GameConfig::sOccupationwarInfo			GameConfig::_occupateionwar_info;
	int32_t									GameConfig::_occupationwar_guild_skill_id = 0;

	bool GameConfig::Initialize(const std::string& file_path)
	{
		if (false == _initialize)
		{
			_initialize = true;
						
			std::string config_filename = file_path + DIRECTORY_SEPARATOR_STRING + "config.json";

			if (false == OpenConfingFile(config_filename))
				return false;

			config_filename = file_path + DIRECTORY_SEPARATOR_STRING + "config_etc.json";

			if (false == OpenConfingEtcFile(config_filename))
				return false;
		}

		return true;
	}

	bool GameConfig::SetSVNRevision(int32_t revision)
	{
		if (0 == revision)
			return false;

		_version_info.svn_revision_number = revision;

		return true;
	}

	bool GameConfig::OpenConfingFile(const std::string& filename)
	{
		std::ifstream fs(filename);
		Json::Value root;
		Json::Reader reader;

		if (false == reader.parse(fs, root))
		{
			std::cout << "Failed to parse game configuration. file name : " << filename;
			return false;
		}

		// version_info
		_version_info.svn_revision_number = root["version_info"]["svn_revision_number"].asInt();
		_version_info.version_number = root["version_info"]["version_number"].asString();
		_version_info.table_version_number = root["version_info"]["table_version_number"].asString();

		// server_info
		_server_info.gid	= root["server_info"]["gid"].asInt();
		_server_info.world_gid = CreateWorldGid(_server_info.gid);
		_server_info.index	= root["server_info"]["index"].asInt();
		_server_info.state	= root["server_info"]["state"].asInt();
		std::string server_type_name = root["server_info"]["type"].asString();
		{			
			if (0 == server_type_name.compare("game"))
			{
				_server_info.type = mrpce_server_type::game;
				_game_info.game_sector_size = root["game_info"]["game_sector_size"].asInt();
			}
			else if (0 == server_type_name.compare("gate"))
			{
				_server_info.type = mrpce_server_type::gate;
			}
			else if (0 == server_type_name.compare("indun"))
			{
				_server_info.type = mrpce_server_type::indun;
				_game_info.indun_sector_size = root["game_info"]["indun_sector_size"].asInt();
			}
			else if (0 == server_type_name.compare("community"))
			{
				_server_info.type = mrpce_server_type::community;
			}
			else if (0 == server_type_name.compare("worldindun"))
			{
				_server_info.type = mrpce_server_type::world_indun;
				_game_info.indun_sector_size = root["game_info"]["indun_sector_size"].asInt();
			}
			else if (0 == server_type_name.compare("worldgame"))
			{
				_server_info.type = mrpce_server_type::world_game;
				_game_info.game_sector_size = root["game_info"]["game_sector_size"].asInt();
			}
			else if (0 == server_type_name.compare("worldcommunity"))
			{
				_server_info.type = mrpce_server_type::world_community;
			}
		}
		_server_info.log_path			= root["server_info"]["log_path"].asString();
		_server_info.table_local_load	= root["server_info"]["table_local_load"].asBool();
		_server_info.thread_count		= root["server_info"]["thread_count"].asInt();
		_server_info.eventthread_count	= root["server_info"]["event_thread_count"].asInt();
		_server_info.encryption		    = root["server_info"]["encryption"].asBool();
		_server_info.chat_command		= root["server_info"]["chat_command"].asBool();
		_server_info.ranking_all		= root["server_info"]["ranking_all"].asBool();
//#ifdef _USE_GLOBAL_SERVICE
		_server_info.time_zone			= root["server_info"]["time_zone"].asInt();
//#endif

		// game info
		_game_info.map					= root["game_info"]["map"].asString();
		_game_info.language				= root["game_info"]["language"].asString();
				
		_game_info.max_play_user		= root["game_info"]["max_play_user"].asInt();
		_game_info.version_check		= root["game_info"]["version_check"].asBool();
		_game_info.version				= root["game_info"]["version"].asString();
		_game_info.database_state_check	= root["game_info"]["database_state_check"].asBool();

		// network info
		_network_info.listen.ip			= root["network_info"]["listen"]["ip"].asString();
		_network_info.listen.port		= root["network_info"]["listen"]["port"].asInt();
		_network_info.max_session		= root["network_info"]["max_session"].asInt();
		_network_info.thread_count		= root["network_info"]["thread_count"].asInt();

		// dump info
		_dump_info.create				= root["dump_info"]["create"].asBool();
		_dump_info.path					= root["dump_info"]["path"].asString();
		_dump_info.type					= root["dump_info"]["type"].asInt();

		// observer info
		_observer_info.ip				= root["observer_info"]["host"]["ip"].asString();
		_observer_info.port				= root["observer_info"]["host"]["port"].asInt();

		// updater
		_updater.msec					= root["updater"]["msec"].asInt();
		_updater.respawn_msec			= root["updater"]["respawn_msec"].asInt();
		//_updater.fsm_msec				= root["updater"]["fsm_msec"].asInt() / 1000.f;// 1000.f;
		_updater.fsm_msec				= root["updater"]["fsm_msec"].asInt();
		_updater.channel_msec			= root["updater"]["channel_msec"].asInt();
		_updater.autosave_sec			= root["updater"]["autosave_sec"].asInt() * 1000;	// sec -> msec
		
		// rpc_info		
		_rpc_info.listen.ip				= root["rpc_info"]["listen"]["ip"].asString();
		_rpc_info.listen.port			= root["rpc_info"]["listen"]["port"].asInt();
		_rpc_info.max_session			= root["rpc_info"]["max_session"].asInt();
		_rpc_info.thread_count			= root["rpc_info"]["thread_count"].asInt();
		_rpc_info.update_sec			= root["rpc_info"]["update_sec"].asInt() * 1000;	// sec -> msec
	
		// community
		if (mir3d::mrpce_server_type::community == Server_Type() || mir3d::mrpce_server_type::world_community == Server_Type())
		{
			const Json::Value community = root["community"]["list"];

			for (uint32_t i = 0; i < community.size(); i++)
			{
				sCommunity info;

				std::string name = community[i]["name"].asString();
				std::transform(name.begin(), name.end(), name.begin(), ::tolower);

				info.name.assign(name);
				info.thread_count = community[i]["thread_count"].asInt();;
				info.run_msec = community[i]["run_msec"].asInt();;

				_list_community.push_back(info);
			}
		}

		for (int32_t i = 0; i < (int32_t)mpe_occupationwar_schedule_type::max; i++)
		{
			_occupateionwar_info.schedule_info.list_datetime.push_back(0);
		}

		return true;
	}

	bool GameConfig::OpenConfingEtcFile(const std::string& filename)
	{
		std::ifstream fs(filename);
		Json::Value root;
		Json::Reader reader;

		if (false == reader.parse(fs, root))
		{
			std::cout << "Failed to parse game configuration etc : " << reader.getFormattedErrorMessages();
			return false;
		}

		// pool
		const Json::Value pool = root["pool"];
		for (uint32_t i = 0; i < pool.size(); i++)
		{
			std::string tempName = pool[i]["name"].asString();

			if (0 == tempName.compare("game"))
			{
				const Json::Value list = pool[i]["list"];

				for (uint32_t j = 0; j < list.size(); j++)
				{
					sPoolInfo info;

					std::string name = list[j]["name"].asString();
					std::transform(name.begin(), name.end(), name.begin(), ::tolower);

					info.name.assign(name);
					info.default_size = list[j]["default_size"].asInt();;
					info.create_size = list[j]["create_size"].asInt();;

					_list_pool.push_back(info);
				}

				break;
			}
		}

		return true;
	}

	GameConfig::sPoolInfo* GameConfig::GetPoolInfo(const std::string& name)
	{
		std::string temp = name;
		std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

		for (size_t i = 0; i < _list_pool.size(); i++)
		{
			if (0 == (_list_pool)[i].name.compare(temp))
			{
				return &(_list_pool)[i];
			}
		}

		return nullptr;
	}

	GameConfig::sCommunity* GameConfig::GetCommunityInfo(const std::string& name)
	{
		std::string temp = name;
		std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

		for (size_t i = 0; i < _list_community.size(); i++)
		{
			if (0 == (_list_community)[i].name.compare(temp))
			{
				return &(_list_community)[i];
			}
		}

		return nullptr;
	}

	std::vector<std::string> GameConfig::GetCreateMap()
	{
		std::vector<std::string> result;
		std::stringstream ss(_game_info.map);
		std::string temp;
		while (std::getline(ss, temp, ','))
		{
			result.push_back(temp);
		}

		return result;
	}
}	// namespace mir3d