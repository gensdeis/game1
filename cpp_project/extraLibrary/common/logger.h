#pragma once

#include <boost/filesystem.hpp>
#include "mirapi.h"
#include "config.h"


namespace mir3d
{
	class Logger
	{
	public:
		static void Initialize(const std::string& base_path, const int minloglevel = 0, const bool write_file = false, const bool print_console = true)
		{
			//google::InitGoogleLogging("mir");

			//FLAGS_logtostderr = write_file;	// 파일 출력 금지 여부 (false면 출력)
			//FLAGS_alsologtostderr = print_console;	// console 출력 여부
			//FLAGS_colorlogtostderr = true;	// console창에 color 출력 여부
			//FLAGS_log_prefix = true;	// glog 기본 log내용 출력여부
			//FLAGS_max_log_size = 1024;	// log 파일 최대 크기 설정 (MB단위)
			//FLAGS_logbuflevel = -1;	// 로그를 버퍼에 담았다가 파일 출력할지 여부 (-1 : 즉시 출력. 기본값은 0(INFO level log만 버퍼에 담음))
			//FLAGS_minloglevel = minloglevel; // 최소 출력 로그레벨 설정. (0 : 모두 출력, 1 : INFO레벨 미출력, 2 : INFO,WARN 미출력(액션로그 출력안됨), 3 : INFO,WARN,ERROR 모두 미출력)

			//const std::string log_path = base_path + DIRECTORY_SEPARATOR_STRING + GameConfig::Server_LogPath() + DIRECTORY_SEPARATOR_STRING;

			//if (false == boost::filesystem::exists(log_path))
			//{
			//	boost::filesystem::create_directory(log_path); 
			//}

			//std::string log_file_base = log_path;

			//const mrpce_server_type server_type = GameConfig::Server_Type();	
			//const int32_t server_gid = GameConfig::Server_Gid();
			//const int32_t server_index = GameConfig::Server_Index();

			//if (server_type == mrpce_server_type::game)
			//{
			//	log_file_base += "game";
			//}
			//else if (server_type == mrpce_server_type::indun)
			//{
			//	log_file_base += "indun";
			//}
			//else if (server_type == mrpce_server_type::community)
			//{
			//	log_file_base += "community";
			//}
			//else if (server_type == mrpce_server_type::aiservice)
			//{
			//	log_file_base += "aiservice";
			//}
			//else
			//{
			
			//SERVER_LOG(eServerLogType::eWarning, "invalid server type. check config.json.";
			//}

			//log_file_base += "_" + std::to_string(server_gid) + "_" + std::to_string(server_index) + "_";

			//const std::string log_file_info = log_file_base + "INFO_";
			//const std::string log_file_error = log_file_base + "ERROR_";

			//// 로그파일명 형식 : {server type}_{gid}_{server index}_{log level}_{datetime}.{process id}
			//// 예시 : game_50001_10001_INFO_20190628-150144.8736

			//google::SetLogDestination(google::GLOG_INFO, log_file_info.c_str());
			//google::SetLogDestination(google::GLOG_ERROR, log_file_error.c_str());
		}
	};

}	// namespace mir3d