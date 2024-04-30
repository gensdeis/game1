#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_street_stall_fees 
	{
	public:
		mpe_good_pos pos{};
	public:
		int32_t value{};

	public:
		mps_street_stall_fees()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
