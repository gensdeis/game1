#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_npc_buy_count 
	{
	public:
		int32_t shop_group_id{};
	public:
		int32_t product_tid{};
	public:
		int32_t limit_type{};	// table::LIMIT_TYPE
	public:
		int32_t count{};	// 구매수량
	public:
		int32_t last_buy_date{};	// 마지막 구매일

	public:
		mps_npc_buy_count()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &shop_group_id);
			protocol::SerializeType(pBuffer, &product_tid);
			protocol::SerializeType(pBuffer, &limit_type);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &last_buy_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
