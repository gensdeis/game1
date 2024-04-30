#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_global_exchange_realtimeprice 
	{
	public:
		uint16_t id{};
	public:
		int64_t buy_count{};
	public:
		float sum_price{};
	public:
		float min_price{};
	public:
		int32_t min_count{};
	public:
		float max_price{};
	public:
		int32_t max_count{};
	public:
		float recent_price{};	// 최근거래가
	public:
		int32_t recent_count{};

	public:
		mrpcs_global_exchange_realtimeprice()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &buy_count);
			protocol::SerializeType(pBuffer, &sum_price);
			protocol::SerializeType(pBuffer, &min_price);
			protocol::SerializeType(pBuffer, &min_count);
			protocol::SerializeType(pBuffer, &max_price);
			protocol::SerializeType(pBuffer, &max_count);
			protocol::SerializeType(pBuffer, &recent_price);
			protocol::SerializeType(pBuffer, &recent_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
