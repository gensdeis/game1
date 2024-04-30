#pragma once

#include <common/singleton.hpp>
#include <condition_variable>
#include <mutex>

namespace mir3d
{
	class CWaitForShutdown : public CSingleton<CWaitForShutdown>
	{
	public:
		CWaitForShutdown() = default;
		~CWaitForShutdown() = default;

	public:
		void Wait(void)
		{
			std::unique_lock<std::mutex> lock(_mutext);
			_condition.wait(lock, [&]() -> bool { return _shutdown_flag; });
		}

		void Shutdown(void)
		{
			std::unique_lock<std::mutex> lock(_mutext);
			_shutdown_flag = true;
			_condition.notify_one();
		}

		inline bool GetShutdownFlag() { return _shutdown_flag; }

	private:
		std::mutex _mutext;
		std::condition_variable _condition;
		bool _shutdown_flag = false;

	private:
		CWaitForShutdown(const CWaitForShutdown&) = delete;
		CWaitForShutdown& operator=(const CWaitForShutdown&) = delete;
		CWaitForShutdown(CWaitForShutdown&&) = delete;
		CWaitForShutdown& operator=(CWaitForShutdown&&) = delete;
	};
	#define waitForShutdown CWaitForShutdown::getInstance()

}	// namespace mir3d

