#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_cash_shop_item 
	{
	public:
		int32_t id{};
	public:
		mpe_cash_shop_item_state state{};
	public:
		int32_t sale_start{};
	public:
		int32_t sale_end{};

	public:
		mps_cash_shop_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &sale_start);
			protocol::SerializeType(pBuffer, &sale_end);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
