#pragma once
#include <vector>
#include <string>
#include "mps_siege_warfare_alliance.h"
#include "mps_siege_machine.h"
#include "mps_siege_machine.h"

namespace mir3d
{
	class mps_siege_warfare_info 
	{
	public:
		mpe_siege_castle_type castle_type{};	// 공성전 type
	public:
		mpe_siege_warfare_state state{};	// 공성전 상태
	public:
		int64_t siege_time{};	// 공성전 날짜
	public:
		int64_t first_guid{};	// 1위길드
	public:
		int32_t current_tender{};	// 현재 입찰최대금
	public:
		int32_t next_min_tender{};	// 다음 입찰최소금
	public:
		int32_t next_max_tender{};	// 다음 입찰최대금
	public:
		std::vector<mps_siege_warfare_alliance> alliance_info{};	// 연합정보
	public:
		int64_t siege_start_time{};	// 공성전 시작날짜및 시간
	public:
		std::vector<mps_siege_machine> atk_machine{};	// 공성 무기
	public:
		std::vector<mps_siege_machine> def_machine{};	// 수성 무기

	public:
		mps_siege_warfare_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &siege_time);
			protocol::SerializeType(pBuffer, &first_guid);
			protocol::SerializeType(pBuffer, &current_tender);
			protocol::SerializeType(pBuffer, &next_min_tender);
			protocol::SerializeType(pBuffer, &next_max_tender);
			protocol::SerializeType(pBuffer, &alliance_info);
			protocol::SerializeType(pBuffer, &siege_start_time);
			protocol::SerializeType(pBuffer, &atk_machine);
			protocol::SerializeType(pBuffer, &def_machine);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
