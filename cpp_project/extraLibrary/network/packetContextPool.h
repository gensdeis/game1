#pragma once

#include <common/define.h>
#include <common/concurrentStackPool.hpp>
#include "networkConfig.h"
#include "packetContext.h"

namespace mir3d
{
	class PacketContextPool
	{
	public:
		static void Initialize(const NetworkConfig::sPoolInfo* info, const int32_t& network_worker_count)
		{
 
			_max_pool_count = network_worker_count;

			for (int32_t i = 0; i < _max_pool_count; i++)
			{
				auto pool = new CStackPool<packetContext>(info->default_size, info->create_size, info->name + "_" + std::to_string(i));

				_list_pool.push_back(pool);
			}			
		}

		static void Destroy(void)
		{
			for (int32_t i = 0; i < static_cast<int32_t>(_list_pool.size()); i++)
			{
				SAFE_DELETE(_list_pool[i]);
			}
			_list_pool.clear();
		}

	public:
		static packetContext* Pop(void)
		{
			int32_t index = 0;
			if (mir3d::Int64_MaxValue > _pool_index.load())
			{
				index = _pool_index.fetch_add(1) % _max_pool_count;
			}
			else
			{
				_pool_index.exchange(0);
			}
			
			auto item = _list_pool[index]->Pop();
			item->pool_index = index;
			return item;
		}

		static void Push(packetContext* item)
		{
			_list_pool[item->pool_index]->Push(item);
		}

	private:
		static std::vector<CStackPool<packetContext>*>	_list_pool;
		static std::atomic<int64_t>						_pool_index;
		static int32_t									_max_pool_count;
	};

}	// namespace mir3d
