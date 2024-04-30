#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_cart_item 
	{
	public:
		int64_t uid{};
	public:
		int32_t table_id{};
	public:
		int32_t buy_time{};
	public:
		int32_t expire_time{};

	public:
		mps_cart_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &buy_time);
			protocol::SerializeType(pBuffer, &expire_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
