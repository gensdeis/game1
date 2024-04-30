#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_street_stall_owner_stat 
	{
	public:
		int32_t ability_calculation_list{};	// table::ABILITY_CALCULATION_LIST
	public:
		int32_t value{};

	public:
		mps_street_stall_owner_stat()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &ability_calculation_list);
			protocol::SerializeType(pBuffer, &value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
