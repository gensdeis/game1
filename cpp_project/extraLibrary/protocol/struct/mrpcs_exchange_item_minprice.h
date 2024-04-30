#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_exchange_item_minprice 
	{
	public:
		int32_t tid{};
	public:
		float min_price{};
	public:
		bool reinforce_flag{};
	public:
		int32_t reinforce{};

	public:
		mrpcs_exchange_item_minprice()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &min_price);
			protocol::SerializeType(pBuffer, &reinforce_flag);
			protocol::SerializeType(pBuffer, &reinforce);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
