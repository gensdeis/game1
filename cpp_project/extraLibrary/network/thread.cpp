#include "stdafx_net.h"
#include "thread.h"
#include <common/serverlogManager.h>

namespace mir3d
{

	CThread::CThread(int32_t wait_msec, const std::string& name) : _wait_msec(wait_msec)
	{
		_name.assign(name);
		_list_thread.clear();
	}


	CThread::~CThread()
	{
		if (_loop_event)
		{
			Destroy();
		}
	}

	void CThread::Initialize(int32_t thread_count, bool suspend)
	{
		for (int32_t thread_index = 0; thread_index < thread_count; thread_index++)
		{
			std::thread* thread = new std::thread(std::bind(&CThread::Worker, this, thread_index, suspend));
			_list_thread.push_back(thread);
		}

		Begin();
	}

	void CThread::Start(void)
	{
		{
			std::lock_guard<std::mutex> lock(_mutex_suspend);
			_suspend_flag = true;
		}

		_suspend_condition.notify_all();
	}

	void CThread::PrepareDestroy(void)
	{
		_loop_event = false;

		if (false == _suspend_flag)
		{
			Start();

			std::chrono::milliseconds duration(100);

			std::this_thread::sleep_for(duration);
		}
	}

	void CThread::Destroy(void)
	{		
		PrepareDestroy();

		for (const auto& item : _list_thread)
		{
			if (true == item->joinable())
			{
				item->join();
			}
		}

		for (auto& item : _list_thread)
		{
			delete item;
		}

		_list_thread.clear();

		End();
	}

	void CThread::Worker(int32_t thread_index, bool suspend)
	{
		// thread 생성되면 suspend 상태로 만든다.
		if (suspend)
		{
			std::unique_lock<std::mutex> lock(_mutex_suspend);
			_suspend_condition.wait(lock, [&]() -> bool
			{
				return _suspend_flag;
			});
		}

		std::chrono::milliseconds duration(_wait_msec);
				
		{
			std::stringstream thead_id;
			thead_id << std::this_thread::get_id();
			SERVER_LOG(eServerLogType::eInfo, "CThread::Worker() start, name : %s, thread_index : %d, thread id : %s", _name.c_str(), thread_index, thead_id.str().c_str());
		}

#ifdef _WINDOWS	
#else
		// _wait_msec
		useconds_t wait_msec = (useconds_t)_wait_msec * 1000;
#endif

		while (_loop_event)
		{
			// std::this_thread::sleep_for(duration);
#ifdef _WINDOWS	
			Sleep(_wait_msec);
#else
			// usleep(1);		// 1 / 1000000 sec
			usleep(wait_msec);
#endif			
			if (false == Run(thread_index))
			{
				break;
			}
		}

		{
			std::stringstream thead_id;
			thead_id << std::this_thread::get_id();
			SERVER_LOG(eServerLogType::eInfo, "CThread::Worker() exit, name : %s, thread_index : %d, thread id : %s", _name.c_str(), thread_index, thead_id.str().c_str());
		}
	}

}	// namespace mir3d