#pragma once

#include <mutex>
#include <unordered_map>
#include <common/singleton.hpp>

namespace mir3d
{	
	class CProfileManager : public CSingleton<CProfileManager>
	{
	public:
		CProfileManager() = default;
		virtual ~CProfileManager() = default;

		void Start(const char* tag_name);
		void Stop(const char* tag_name, const int safe_time);

	private:
		typedef unsigned long ThreadID;
		typedef std::unordered_map<std::string, uint64_t> TIMER_MAP;

		std::unordered_map<ThreadID, TIMER_MAP*> _timer_map;
		std::mutex _mutex;

	private:
		CProfileManager(const CProfileManager&) = delete;
		CProfileManager& operator=(const CProfileManager&) = delete;
		CProfileManager(CProfileManager&&) = delete;
		CProfileManager& operator=(CProfileManager&&) = delete;
	};

	#define profileManager CProfileManager::getInstance()
}
