#pragma once
#include <vector>
#include <string>
#include "mrpcs_summon_object_wave_info.h"

namespace mir3d
{
	class mrpcs_summon_object_info 	// 소환 오브젝트의 정보
	{
	public:
		int32_t object_id{};	// Fixed_Object_Table 참조
	public:
		int32_t object_position{};	// Map_Object_Data_Table 참조
	public:
		std::vector<mrpcs_summon_object_wave_info> wave_list{};	// 각 웨이브의 정보

	public:
		mrpcs_summon_object_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &object_id);
			protocol::SerializeType(pBuffer, &object_position);
			protocol::SerializeType(pBuffer, &wave_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
