#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_wemix_shop_buy_count 
	{
	public:
		int32_t table_id{};
	public:
		uint8_t count{};
	public:
		int32_t last_buy_date{};
	public:
		int32_t cart_count{};
	public:
		int32_t buy_count{};

	public:
		mrpcs_wemix_shop_buy_count()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &last_buy_date);
			protocol::SerializeType(pBuffer, &cart_count);
			protocol::SerializeType(pBuffer, &buy_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
