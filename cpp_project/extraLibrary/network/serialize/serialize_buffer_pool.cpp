#include "stdafx_net.h"
#include "serialize_buffer_pool.h"
#include <common/serverlogManager.h>

namespace mir3d
{
	CSerializeBufferPool::CSerializeBufferPool(int32_t defaultSize, int32_t createSize) : CMemPool(defaultSize, createSize, "CSerializeBufferPool", OnMempoolAllocLogger)
	{
	}

	CSerializeBufferPool::~CSerializeBufferPool()
	{
	}

	void CSerializeBufferPool::Push(protocol::SerializeBufferNative* item)
	{
		if (nullptr != item)
		{
			item->Reset();
			CMemPool::Push(item);
		}
	}
};	// namespace mir3d