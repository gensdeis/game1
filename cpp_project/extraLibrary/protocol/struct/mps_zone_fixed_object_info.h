#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_zone_fixed_object_info 
	{
	public:
		int32_t hp{};	// HP
	public:
		int32_t mhp{};	// maxHP
	public:
		int32_t table_index{};	// siege_table 에서 오브젝트의 인덱스
	public:
		uint8_t phase{};	// step hp

	public:
		mps_zone_fixed_object_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &hp);
			protocol::SerializeType(pBuffer, &mhp);
			protocol::SerializeType(pBuffer, &table_index);
			protocol::SerializeType(pBuffer, &phase);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
