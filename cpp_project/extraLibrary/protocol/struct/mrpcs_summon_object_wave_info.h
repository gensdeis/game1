#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_summon_object_wave_info 	// 소환 오브젝트의 소환 웨이브 정보
	{
	public:
		int32_t wait_second{};	// 소환 전 대기 시간
	public:
		int32_t summon_id{};	// Summon_Group_Table 참조 소환 몬스터 리스트

	public:
		mrpcs_summon_object_wave_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &wait_second);
			protocol::SerializeType(pBuffer, &summon_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
