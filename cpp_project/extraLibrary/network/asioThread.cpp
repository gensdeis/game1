#include "stdafx_net.h"
#include "asioThread.h"
#include <common/serverlogManager.h>

namespace mir3d
{
	CAsioThread::CAsioThread(std::vector<std::shared_ptr<boost::asio::io_service>>& list_io_service) : _list_io_service(list_io_service)
	{
		for (auto io_service : _list_io_service)
		{
			std::shared_ptr<boost::asio::io_service::work> work(new boost::asio::io_service::work(*io_service));
			_list_io_worker.push_back(work);
		}
	}	

	void CAsioThread::Create(const std::string& name)
	{
		for (auto io_service : _list_io_service)
		{
			std::shared_ptr<std::thread> thread(new std::thread(boost::bind(&boost::asio::io_service::run, io_service)));

			_list_threads.push_back(thread);

			std::stringstream thead_id;
			thead_id << thread->get_id();
			SERVER_LOG(eServerLogType::eInfo, "CAsioThread::Create() server : %s, thread id : %s", name.c_str(), thead_id.str().c_str());
		}
	}

	void CAsioThread::Destroy(void)
	{
		std::chrono::milliseconds duration(500);

		for (auto io_service : _list_io_service)
		{
			io_service->stop();

			while (false == io_service->stopped())
			{
				std::this_thread::sleep_for(duration);
			}
		}

		for (auto thread : _list_threads)
		{
			thread->join();
		}
	}

}	// namespace mir3d