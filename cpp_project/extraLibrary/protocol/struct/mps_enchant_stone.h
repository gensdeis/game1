#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_enchant_stone 
	{
	public:
		int32_t tid{};
	public:
		int32_t grade{};

	public:
		mps_enchant_stone()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &grade);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
