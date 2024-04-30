#include "stdafx_net.h"
#include "profileManager.h"
//#include "g3loger_rotate.h"
#include "util.h"
#include <common/serverlogManager.h>
#include <boost/winapi/get_current_thread_id.hpp>

namespace mir3d
{
	void CProfileManager::Start(const char* tag_name)
	{
		TIMER_MAP* map = nullptr;

		{
			std::lock_guard<std::mutex> lock(_mutex);

			const ThreadID current_tid = GetCurrentThreadId();

			auto iter = _timer_map.find(current_tid);
			if (_timer_map.end() == iter) // not found
			{
				map = new TIMER_MAP();
				_timer_map.insert(std::make_pair(current_tid, map));
				map = _timer_map[current_tid];
			}
			else
			{
				map = iter->second;
			}
		}

		if (0 < map->count(tag_name)) // already exist
		{
			SERVER_LOG(eServerLogType::eWarning, "Tag(%s) is already exist.", tag_name);
			return;
		}

		map->insert(std::make_pair(tag_name, util::mirTime::GetTickMilliCount()));
	}

	void CProfileManager::Stop(const char* tag_name, const int safe_time)
	{
		const uint64_t now = util::mirTime::GetTickMilliCount(); // 아래 map 탐색하는 시간이 영향주지 못하게, 시간 먼저 뽑아냄

		TIMER_MAP* map = nullptr;

		{
			std::lock_guard<std::mutex> lock(_mutex);

			const ThreadID current_tid = GetCurrentThreadId();

			auto iter = _timer_map.find(current_tid);
			if (_timer_map.end() == iter) // not found
			{
				std::stringstream thead_id;
				thead_id << current_tid;
				SERVER_LOG(eServerLogType::eWarning, "Thread(%s) map is not found.", thead_id.str().c_str());
				return;
			}
			else
			{
				map = iter->second;
			}
		}

		auto iter = map->find(tag_name);
		if (map->end() == iter) // not found
		{
			SERVER_LOG(eServerLogType::eWarning, "Tag(%s) is not found.", tag_name);
			return;
		}

		const uint64_t start_time = iter->second;
		const uint64_t elapsed_time = (now - start_time);

		if (safe_time < elapsed_time)
		{
			SERVER_LOG(eServerLogType::eWarning, "Profile time over. Tag : %s. elapsed time(ms) : %I64u", tag_name, elapsed_time);
		}

		map->erase(tag_name);
	}
}
