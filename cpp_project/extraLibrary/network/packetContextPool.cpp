#include "stdafx_net.h"
#include "packetContextPool.h"

namespace mir3d
{	
	std::vector<CStackPool<packetContext>*>		PacketContextPool::_list_pool;
	std::atomic<int64_t>						PacketContextPool::_pool_index = 0;
	int32_t										PacketContextPool::_max_pool_count = 0;
}	// namespace mir3d