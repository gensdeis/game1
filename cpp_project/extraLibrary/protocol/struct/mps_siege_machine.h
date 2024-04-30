#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_siege_machine 	// 공성 무기
	{
	public:
		int32_t table_id{};	// siege_table 아이디
	public:
		mpe_siege_warfare_machine_position machine_position{};	// 무기 설치 위치
	public:
		int32_t item_id{};	// 공성무기 아이디
	public:
		int32_t index{};	// 설치 index
	public:
		int64_t set_cuid{};	// 설치된 공성병기에 할당된 유저cuid

	public:
		mps_siege_machine()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeEnum(pBuffer, &machine_position);
			protocol::SerializeType(pBuffer, &item_id);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &set_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
