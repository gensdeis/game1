#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_exchange_reinforce_count 
	{
	public:
		int32_t reinforce{};
	public:
		int32_t count{};
	public:
		int32_t price{};

	public:
		mps_exchange_reinforce_count()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &reinforce);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &price);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
