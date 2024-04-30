#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_global_exchange_sell_item 
	{
	public:
		int32_t i{};	// tid
	public:
		int32_t c{};	// count
	public:
		float p{};	// price

	public:
		mps_global_exchange_sell_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &i);
			protocol::SerializeType(pBuffer, &c);
			protocol::SerializeType(pBuffer, &p);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
