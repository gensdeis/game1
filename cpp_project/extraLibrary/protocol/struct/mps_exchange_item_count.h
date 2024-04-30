#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_exchange_item_count 
	{
	public:
		int32_t id{};
	public:
		int32_t count{};
	public:
		int32_t price{};

	public:
		mps_exchange_item_count()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &price);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
