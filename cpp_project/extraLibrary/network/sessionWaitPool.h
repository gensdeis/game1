#pragma once

#include "networkConfig.h"
#include <common/concurrentMemPool.hpp>

namespace mir3d
{
	typedef void (*updateFuntionHandler)(const uint64_t& now_time);

	class SessionWaitPool
	{
	public:
		struct waitItem
		{
			uint64_t		expire_time;
			int64_t			session_id;

			void reset(void)
			{
				expire_time = 0;
				session_id = 0;
			}
		};
		
	public:
		static void Initialize(const NetworkConfig::sPoolInfo* info);
		static void Destroy(void);

	public:
		static void Push(const int64_t session_id);
		static void PushDisconnect(const int64_t session_id);
		static void Update(void);
		static void UpdateFunction(void (*func)(const uint64_t& now_time));
		// Web Daemon 추가로 필요
		static int32_t GetWaitingSeesionPoolSize();
		static int32_t GetDisconnectSeesionPoolSize();

		static updateFuntionHandler				_func;

	private:
		static CMemPool<waitItem>*    			_pool;
		static CConcurrentQueue<waitItem*>*		_queue;
		static uint64_t							_limit_time;

		static CConcurrentQueue<waitItem*>* _queue_disconnect;
	};
}	// namespace mir3d