#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_exchange_search_item 
	{
	public:
		int32_t id{};
	public:
		int32_t price{};
	public:
		int32_t count{};

	public:
		mps_exchange_search_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &price);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
