#include "stdafx_net.h"
#include "networkConfig.h"
#include <common/serverlogManager.h>
#include <protocol/mrpc_update_not_allow_packet.h>

namespace mir3d
{
	bool									NetworkConfig::_initialize = false;
	std::vector<NetworkConfig::sPoolInfo>*	NetworkConfig::_list_pool = nullptr;
	int32_t									NetworkConfig::_socket_readpool = 0;
	NetworkConfig::sHeartbeat				NetworkConfig::_heartbeat_info;
	int32_t									NetworkConfig::_reconnect_try_count = 0;

	bool									NetworkConfig::_is_show_networklog = false;

	std::string								NetworkConfig::_server_name = "";
	std::string								NetworkConfig::_config_filename;
	Json::Value								NetworkConfig::_config_json_root;

#ifdef _USE_NEW_NOT_ALLOW_PACKET
	bool									NetworkConfig::_update_packet_not_allow_check = false;

	NetworkConfig::sPakcetNotAllowCheck		NetworkConfig::_game_packet_not_allow_check;
	NetworkConfig::sPakcetNotAllowCheck		NetworkConfig::_community_packet_not_allow_check;
#endif

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
	NetworkConfig::sDuplicationLogin		NetworkConfig::_use_not_allow_duplication_login;
#endif

	NetworkConfig::sRpcHeartbeat			NetworkConfig::_rpc_heartbeat_info;


	bool NetworkConfig::Initialize(const std::string& filename)
	{
		if (false == _initialize)
		{
			_initialize = true;

			_list_pool = new std::vector<sPoolInfo>();

			return OpenFile(filename);
		}

		return true;
	}

	void NetworkConfig::Destroy(void)
	{
		if (nullptr != _list_pool)
		{
			delete _list_pool;
		}
	}

	NetworkConfig::sPoolInfo* NetworkConfig::GetPoolInfo(const std::string& name)
	{
		std::string temp = name;
		std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

		for (size_t i = 0; i < _list_pool->size(); i++)
		{
			if (0 == (*_list_pool)[i].name.compare(temp))
			{
				return &(*_list_pool)[i];
			}
		}

		return nullptr;
	}

	bool NetworkConfig::OpenFile(const std::string& filename)
	{
		std::ifstream fs(filename);
		// Json::Value root;
		Json::Reader reader;

		_config_filename = filename;

		if (false == reader.parse(fs, _config_json_root))
		{
			SERVER_LOG(eServerLogType::eDebug, "Failed to parse configuration : %s", reader.getFormattedErrorMessages());
			return false;
		}

		// pool
		const Json::Value pool = _config_json_root["pool"];
		// int32_t size = data["pool"].Size();
		for (uint32_t i = 0; i < pool.size(); i++)
		{
			std::string tempName = pool[i]["name"].asString();

			if (0 == tempName.compare("network"))
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
					info.reserve_value = list[j]["reserve_value"].asInt();;

					_list_pool->push_back(info);
				}

				break;
			}
		}

		_socket_readpool = _config_json_root["socket"]["socket_readpool"].asInt();
		_reconnect_try_count = _config_json_root["socket"]["reconnect_try_count"].asInt();

		_heartbeat_info.check_heartbeat = _config_json_root["socket_heartbeat"]["check_heartbeat"].asBool();
		_heartbeat_info.check_time = _config_json_root["socket_heartbeat"]["check_time"].asInt();
		_heartbeat_info.interval = _config_json_root["socket_heartbeat"]["interval"].asInt();
		_heartbeat_info.check_count = _config_json_root["socket_heartbeat"]["check_count"].asInt();
		_heartbeat_info.speed_hack_check = _config_json_root["socket_heartbeat"]["speed_hack_check"].asBool();
		_heartbeat_info.speed_hack_check_count = _config_json_root["socket_heartbeat"]["speed_hack_check_count"].asInt();

#ifdef _USE_NEW_NOT_ALLOW_PACKET
		_game_packet_not_allow_check.packet_check = _config_json_root["game_socket_not_allow_packet"]["packet_check"].asBool();
		if (_game_packet_not_allow_check.packet_check)
		{
			const Json::Value list = _config_json_root["game_socket_not_allow_packet"]["list"];

			for (int32_t i = 0; i < static_cast<int32_t>(list.size()); i++)
			{
				sPakcetNotAllow packet;

				packet.cmd = list[i]["cmd"].asInt();
				packet.limit_time = list[i]["limit_time"].asInt();

				_game_packet_not_allow_check.list.push_back(packet);
			}
		}

		_community_packet_not_allow_check.packet_check = _config_json_root["community_socket_not_allow_packet"]["packet_check"].asBool();
		if (_community_packet_not_allow_check.packet_check)
		{
			const Json::Value list = _config_json_root["community_socket_not_allow_packet"]["list"];

			for (int32_t i = 0; i < static_cast<int32_t>(list.size()); i++)
			{
				sPakcetNotAllow packet;

				packet.cmd = list[i]["cmd"].asInt();
				packet.limit_time = list[i]["limit_time"].asInt();

				_game_packet_not_allow_check.list.push_back(packet);
			}
		}
#endif

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
		_use_not_allow_duplication_login.check_duplication_login = _config_json_root["use_not_allow_duplication_login"]["check"].asBool();
		_use_not_allow_duplication_login.interval = _config_json_root["use_not_allow_duplication_login"]["interval"].asInt();
#endif

		_rpc_heartbeat_info.use = _config_json_root["rpc_socket_heartbeat"]["use"].asBool();
		_rpc_heartbeat_info.keep_alive_interval = _config_json_root["rpc_socket_heartbeat"]["keep_alive_interval"].asInt();
		_rpc_heartbeat_info.retry_limit_count = _config_json_root["rpc_socket_heartbeat"]["retry_limit_count"].asInt();
		_rpc_heartbeat_info.latency_check_time = _config_json_root["rpc_socket_heartbeat"]["latency_check_time"].asInt();

		return true;
	}

	void NetworkConfig::WriteFile()
	{
		std::ofstream fs(_config_filename);
		Json::StyledWriter writer;

		std::string json_string = writer.write(_config_json_root);

		fs << json_string;

		fs.close();
	}

	void NetworkConfig::UpdateSpeedHackCheck(bool check_state, int32_t check_count)
	{
		_config_json_root["socket_heartbeat"]["speed_hack_check"] = check_state;
		_config_json_root["socket_heartbeat"]["speed_hack_check_count"] = check_count;

		WriteFile();

		_heartbeat_info.speed_hack_check = check_state;
		_heartbeat_info.speed_hack_check_count = check_count;

		//SERVER_LOG(eServerLogType::eInfo, "UpdateSpeedHackCheck() check_state : %d, check_count : %d", check_state, check_count);
		SERVER_LOG(eServerLogType::eInfo, "UpdateSpeedHackCheck() check_state : %d, check_count : %d", check_state, check_count);
	}

#ifdef _USE_NOT_ALLOW_DUPLICATION_LOGIN
	void NetworkConfig::UpdateUseNotAllowDuplicationLogin(const bool& check_state)
	{
		SERVER_LOG(eServerLogType::eInfo, "UpdateUseNotAllowDuplicationLogin() check state : %d", check_state);

		SetUseNotAllowDuplicationLogin(check_state);
	}
#endif

	void NetworkConfig::UpdateNotAllowPacket(mir3d::mrpc_update_not_allow_packet_cs& packet)
	{
		// 0 : game 1 : community
		if (0 == packet.flag)
		{
			_config_json_root["game_socket_not_allow_packet"]["packet_check"] = packet.check_state;
			_game_packet_not_allow_check.packet_check = packet.check_state;

			//SERVER_LOG(eServerLogType::eInfo, "UpdateNotAllowPacket() game,  check_state : %d", packet.check_state);
			SERVER_LOG(eServerLogType::eInfo, "UpdateNotAllowPacket() game,  check_state : %d", packet.check_state);

			if (packet.check_state)
			{
				_game_packet_not_allow_check.list.clear();

				Json::Value json_list;

				auto info = packet.get_info();

				if (nullptr != info && 0 < info->list.size())
				{
					for (int32_t i = 0; i < static_cast<int32_t>(info->list.size()); i++)
					{
						sPakcetNotAllow temp;

						temp.cmd = info->list[i].cmd;
						temp.limit_time = info->list[i].limit_time;

						Json::Value item;
						item["cmd"] = temp.cmd;
						item["limit_time"] = temp.limit_time;

						json_list.append(item);

						_game_packet_not_allow_check.list.push_back(temp);

						SERVER_LOG(eServerLogType::eInfo, "UpdateNotAllowPacket() packet,  cmd : %d, limit_time : %d", temp.cmd, temp.limit_time);
					}
				}

				_config_json_root["game_socket_not_allow_packet"]["list"] = json_list;
			}
		}
		else
		{
			_config_json_root["community_socket_not_allow_packet"]["packet_check"] = packet.check_state;
			_community_packet_not_allow_check.packet_check = packet.check_state;

			//SERVER_LOG(eServerLogType::eInfo, "UpdateNotAllowPacket() community,  check_state : %d", packet.check_state);
			SERVER_LOG(eServerLogType::eInfo, "UpdateNotAllowPacket() community,  check_state : %d", packet.check_state);

			if (packet.check_state)
			{
				_community_packet_not_allow_check.list.clear();

				Json::Value json_list;

				auto info = packet.get_info();

				if (nullptr != info && 0 < info->list.size())
				{
					for (int32_t i = 0; i < static_cast<int32_t>(info->list.size()); i++)
					{
						sPakcetNotAllow temp;

						temp.cmd = info->list[i].cmd;
						temp.limit_time = info->list[i].limit_time;

						Json::Value item;
						item["cmd"] = temp.cmd;
						item["limit_time"] = temp.limit_time;

						json_list.append(item);

						_community_packet_not_allow_check.list.push_back(temp);

						SERVER_LOG(eServerLogType::eInfo, "UpdateNotAllowPacket() packet,  cmd : %d, limit_time : %d", temp.cmd, temp.limit_time);
					}
				}

				_config_json_root["community_socket_not_allow_packet"]["list"] = json_list;
			}
		}

		WriteFile();

		_update_packet_not_allow_check = true;
	}
}	// namespace mir3d