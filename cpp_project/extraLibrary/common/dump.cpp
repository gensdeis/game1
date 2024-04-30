#include "stdafx_net.h"
#ifdef _WINDOWS

#include "dump.h"

#include <boost/algorithm/string/replace.hpp>
#include <DbgHelp.h>

#include <common/config.h>
#include <common/serverlogManager.h>

namespace mir3d
{
	void Dump::Initialize()
	{
		// exception 처리 안되면 CreateDumpThread() 호출
		SetUnhandledExceptionFilter(CreateDumpThread);
	}

	long __stdcall Dump::CreateDumpThread(PEXCEPTION_POINTERS pException)
	{
		SERVER_LOG(eServerLogType::eDebug, "start to create dump.");

		CrashInfo crashInfo;
		crashInfo.threadId = GetCurrentThreadId();
		crashInfo.pException = pException;

		std::thread thread_making_dump(CreateDump, &crashInfo);

		thread_making_dump.join();

		SERVER_LOG(eServerLogType::eDebug, "finished to create dump.");

		return EXCEPTION_EXECUTE_HANDLER;
	}

	void Dump::CreateDump(CrashInfo* pCrashInfo)
	{
		if (nullptr == pCrashInfo)
		{
			SERVER_LOG(eServerLogType::eDebug, "pCrashInfo is null.");
			return;
		}

		// dump file name 설정
		//const std::wstring dump_file_name_wstr = MakeDumpFileName();

		//wchar_t dump_file_name[256];
		//wcscpy_s(dump_file_name, dump_file_name_wstr.c_str());

		//HANDLE file_handle = CreateFile(dump_file_name, GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_WRITE_THROUGH, NULL);
		HANDLE file_handle = CreateFileA(MakeDumpFileName().c_str(), GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_WRITE_THROUGH, NULL);

		if (INVALID_HANDLE_VALUE == file_handle)
		{
			SERVER_LOG(eServerLogType::eDebug, "fail to create file handle.");
			CloseHandle(file_handle);
			return;
		}

		MINIDUMP_EXCEPTION_INFORMATION dump_exception_info;
		dump_exception_info.ThreadId = pCrashInfo->threadId;
		dump_exception_info.ExceptionPointers = pCrashInfo->pException;
		dump_exception_info.ClientPointers = FALSE;

		const MINIDUMP_TYPE dump_type = static_cast<MINIDUMP_TYPE>(GameConfig::Dump_Type());

		BOOL result = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), file_handle, dump_type, &dump_exception_info, nullptr, nullptr);

		if (FALSE == result)
		{
			SERVER_LOG(eServerLogType::eDebug, "fail to create dump.");
		}

		CloseHandle(file_handle);
	}

	// const std::wstring Dump::MakeDumpFileName()
	const std::string Dump::MakeDumpFileName()
	{
		std::string dump_file_name = GameConfig::Dump_Path();

		// "\\"이 끝에 없으면 추가
		std::string temp = dump_file_name;
		temp.erase(0, temp.length() - temp.find_last_of(DIRECTORY_SEPARATOR_STRING) + sizeof(DIRECTORY_SEPARATOR_STRING));

		if (temp.empty())
		{
			dump_file_name += DIRECTORY_SEPARATOR_STRING;
		}

		if (false == boost::filesystem::exists(dump_file_name))
		{
			boost::filesystem::create_directory(dump_file_name);
		}

		const mrpce_server_type server_type = GameConfig::Server_Type();
		const int32_t server_gid = GameConfig::Server_Gid();
		const int32_t server_index = GameConfig::Server_Index();

		if (server_type == mrpce_server_type::game)
		{
			dump_file_name += "game";
		}
		else if (server_type == mrpce_server_type::gate)
		{
			dump_file_name += "gate";
		}
		else if (server_type == mrpce_server_type::indun)
		{
			dump_file_name += "indun";
		}
		else if (server_type == mrpce_server_type::community)
		{
			dump_file_name += "community";
		}
		else if (server_type == mrpce_server_type::world_indun)
		{
			dump_file_name += "worldindun";
		}
		else if (server_type == mrpce_server_type::world_game)
		{
			dump_file_name += "worldgame";
		}
		else if (server_type == mrpce_server_type::world_community)
		{
			dump_file_name += "worldcommunity";
		}
		else
		{
			SERVER_LOG(eServerLogType::eDebug, "invalid server type. check config.json.");
		}

		dump_file_name += "_" + std::to_string(server_gid) + "_" + std::to_string(server_index) + "_";

		std::time_t raw_time;
		std::time(&raw_time);
		std::tm time_info;
		int32_t error = localtime_s(&time_info, &raw_time);

		if (NULL != error)
		{
			SERVER_LOG(eServerLogType::eDebug, "fail to get local time."); 
			return "";
		}

		char current_time[256];
		std::strftime(current_time, sizeof(current_time), "%Y%m%d-%H%M%S.dmp", &time_info);
		dump_file_name += current_time;

		return dump_file_name;
		//std::wstring dump_file_name_wstr;
		//dump_file_name_wstr.assign(dump_file_name.begin(), dump_file_name.end());

		//return dump_file_name_wstr;
	}
}

#endif
