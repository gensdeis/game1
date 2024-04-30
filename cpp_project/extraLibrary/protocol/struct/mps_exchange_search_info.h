#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_exchange_search_info 
	{
	public:
		int32_t exchange_type{};
	public:
		int32_t class_type{};
	public:
		int32_t item_id{};

	public:
		mps_exchange_search_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &exchange_type);
			protocol::SerializeType(pBuffer, &class_type);
			protocol::SerializeType(pBuffer, &item_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
