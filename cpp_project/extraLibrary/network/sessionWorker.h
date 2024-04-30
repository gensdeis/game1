#pragma once

#include "sessionPool.h"
#include "worker.h"

namespace mir3d
{
	// session reconnect 처리를 위해 보관 중인 session의 timeout 처리를 위해 사용
	class CSessionWorker : public CWorker
	{
	public:
		CSessionWorker() = delete;
		CSessionWorker(int32_t worker_count, /*int32_t rpc_count, */int32_t wait_msec) : CWorker("SessionWorker", worker_count, /*rpc_count, */wait_msec) {}
		virtual ~CSessionWorker() 
		{
			Destroy();
		}

	public:
		virtual void Initialize(bool suspend = true)
		{
			CThread::Initialize(_worker_count, suspend);
		}

		virtual void Start(void)
		{
			CThread::Start();
		}

		virtual void Destroy(void)
		{
			CThread::Destroy();
		}

	private:
		virtual bool Begin(void)
		{
			return true;
		}

		virtual bool Run(int32_t index)
		{
			SessionWaitPool::Update();
			return true;
		}

		virtual bool End(void)
		{
			return true;
		}

	private:
		CSessionWorker(const CSessionWorker&) = delete;
		CSessionWorker& operator=(const CSessionWorker&) = delete;
		CSessionWorker(CSessionWorker&&) = delete;
		CSessionWorker& operator=(CSessionWorker&&) = delete;
	};

}	// namespace mir3d

