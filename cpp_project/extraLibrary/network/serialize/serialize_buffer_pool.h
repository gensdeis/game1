#pragma once

#include "serialize_buffer.h"
#include <common/concurrentMemPool.hpp>

namespace mir3d
{
	class CSerializeBufferPool : public CMemPool<protocol::SerializeBufferNative>, public CSingleton<CSerializeBufferPool>
	{
	public:
		CSerializeBufferPool(int32_t defaultSize, int32_t createSize);
		virtual ~CSerializeBufferPool();

	public:
		virtual void Push(protocol::SerializeBufferNative* item);

	private:
		CSerializeBufferPool(const CSerializeBufferPool&) = delete;
		CSerializeBufferPool& operator=(const CSerializeBufferPool&) = delete;
		CSerializeBufferPool(CSerializeBufferPool&&) = delete;
		CSerializeBufferPool& operator=(CSerializeBufferPool&&) = delete;
	};
	#define serializeBufferPool CSerializeBufferPool::getInstance()
}	// namespace mir3d