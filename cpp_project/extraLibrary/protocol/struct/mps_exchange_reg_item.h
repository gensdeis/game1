#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_exchange_reg_item 
	{
	public:
		int32_t i{};	// tid
	public:
		int32_t c{};	// count
	public:
		int32_t p{};	// price

	public:
		mps_exchange_reg_item()
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
