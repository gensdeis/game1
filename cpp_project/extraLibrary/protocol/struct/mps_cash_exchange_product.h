#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_cash_exchange_product 
	{
	public:
		std::vector<int32_t> list{};
	public:
		int32_t reset_date{};
	public:
		uint16_t sell_category_id{};	// 보스/명예 

	public:
		mps_cash_exchange_product()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &reset_date);
			protocol::SerializeType(pBuffer, &sell_category_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
