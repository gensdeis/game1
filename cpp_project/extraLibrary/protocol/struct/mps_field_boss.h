#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_field_boss 
	{
	public:
		int32_t monster_id{};	// //tableid
	public:
		int32_t zone_id{};	// 스폰 맵id
	public:
		uint16_t channel_id{};	// 스폰 채널id

	public:
		mps_field_boss()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &monster_id);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &channel_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
