#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_zone_siege_weapon_info 
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
		bool is_open_gate{};	// 공성탑 게이트 활성화 여부

	public:
		mps_zone_siege_weapon_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &hp);
			protocol::SerializeType(pBuffer, &mhp);
			protocol::SerializeType(pBuffer, &table_index);
			protocol::SerializeType(pBuffer, &phase);
			protocol::SerializeType(pBuffer, &is_open_gate);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
