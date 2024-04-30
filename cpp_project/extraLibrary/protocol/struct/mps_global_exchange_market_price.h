#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_global_exchange_market_price 
	{
	public:
		float min_price{};
	public:
		int32_t min_count{};
	public:
		float max_price{};
	public:
		int32_t max_count{};
	public:
		float recent_price{};
	public:
		int32_t recent_count{};
	public:
		int64_t total_count{};
	public:
		float total_price{};

	public:
		mps_global_exchange_market_price()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &min_price);
			protocol::SerializeType(pBuffer, &min_count);
			protocol::SerializeType(pBuffer, &max_price);
			protocol::SerializeType(pBuffer, &max_count);
			protocol::SerializeType(pBuffer, &recent_price);
			protocol::SerializeType(pBuffer, &recent_count);
			protocol::SerializeType(pBuffer, &total_count);
			protocol::SerializeType(pBuffer, &total_price);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
