#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_street_stall_product_info 
	{
	public:
		int32_t product_id{};	// // table id
	public:
		mpe_good_pos good_pos{};
	public:
		int32_t good_value{};

	public:
		mps_street_stall_product_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &product_id);
			protocol::SerializeEnum(pBuffer, &good_pos);
			protocol::SerializeType(pBuffer, &good_value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
