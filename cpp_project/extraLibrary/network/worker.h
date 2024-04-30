#pragma once

#include "thread.h"

namespace mir3d
{
	class CWorker : public CThread
	{
	public:
		CWorker() = delete;
		CWorker(const std::string name, int32_t worker_count, int32_t wait_msec) : CThread(wait_msec, name), _worker_count(worker_count) {}
		virtual ~CWorker() {}
		
		inline int32_t GetWorkerCount() const
		{
			return _worker_count;
		}

	protected:
		int32_t _worker_count = 0;

	private:
		CWorker(const CWorker&) = delete;
		CWorker& operator=(const CWorker&) = delete;
		CWorker(CWorker&&) = delete;
		CWorker& operator=(CWorker&&) = delete;
	};

}	// namespace mir3d
