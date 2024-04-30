#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_global_exchagne_withdraw_gold_type 
	{
	public:
		int64_t luid{};
	public:
		int64_t euid{};
	public:
		int32_t tid{};
	public:
		int32_t count{};
	public:
		uint8_t reinforce{};
	public:
		float price{};
	public:
		float tax{};
	public:
		float sell_price{};
	public:
		int32_t awaken_step{};

	public:
		mrpcs_global_exchagne_withdraw_gold_type()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &luid);
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &reinforce);
			protocol::SerializeType(pBuffer, &price);
			protocol::SerializeType(pBuffer, &tax);
			protocol::SerializeType(pBuffer, &sell_price);
			protocol::SerializeType(pBuffer, &awaken_step);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
