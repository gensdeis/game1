#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_wemix_shop_history 
	{
	public:
		int32_t table_id{};	// cash_shop table id
	public:
		int32_t buy_time{};	// 구매 시간
	public:
		int32_t count{};	// 구매 개수

	public:
		mps_wemix_shop_history()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &buy_time);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
