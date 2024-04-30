#pragma once

#include <common/concurrentMap.hpp>
#include "networkConfig.h"
#include "session.h"
#include "sessionWaitPool.h"

namespace mir3d
{
	class SessionPool
	{
	public:
		static void Initialize(const NetworkConfig::sPoolInfo* info);
		static void Destroy(void);

	public:
		static CSession* Pop(void);
		static void Push(CSession* item);
		static CSession* PopWait(int64_t session_id);
		static CSession* PopWaitDisconnect(int64_t session_id);
		static void PushWait(CSession* session);
		static void PushDisconnect(CSession* const session);


	private:
		static CMemPool<CSession>*    				_pool;
		static CConcurrentMap<int64_t, CSession*>*	_map_wait;		// key : session_id
		static CConcurrentMap<int64_t, CSession*>*	_map_wait_disconnect;		// key : session_id
	};		

}	// namespace mir3d