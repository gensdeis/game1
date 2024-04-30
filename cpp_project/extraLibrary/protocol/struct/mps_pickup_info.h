#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_pickup_info 
	{
	public:
		uint8_t item_type{};
	public:
		int64_t iuid{};
	public:
		int32_t table_id{};
	public:
		int32_t count{};

	public:
		mps_pickup_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &item_type);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
