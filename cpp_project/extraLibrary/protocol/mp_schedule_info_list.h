#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_schedule_info.h"
#include "struct/mps_schedule_info.h"
#include "struct/mps_schedule_info.h"
#include "struct/mps_schedule_info.h"
#include "struct/mps_schedule_info.h"

namespace mir3d
{
	class mp_schedule_info_list_cs : public BasePacket 
	{

	public:
		mp_schedule_info_list_cs() : BasePacket(mpe_cmd::schedule_info_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_schedule_info_list_sc : public BasePacket 
	{
	public:
		std::vector<mps_schedule_info> world_boss_info{};	// 월드보스
	public:
		std::vector<mps_schedule_info> siege_warfare_info{};	// 공성전
	public:
		std::vector<mps_schedule_info> guild_shipwar_info{};	// 혈범전장
	public:
		std::vector<mps_schedule_info> secretvalley_info{};	// 비곡점령전
	public:
		std::vector<mps_schedule_info> arena_battle_info{};	// 수라전장

	public:
		mp_schedule_info_list_sc() : BasePacket(mpe_cmd::schedule_info_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &world_boss_info);
			protocol::SerializeType(pBuffer, &siege_warfare_info);
			protocol::SerializeType(pBuffer, &guild_shipwar_info);
			protocol::SerializeType(pBuffer, &secretvalley_info);
			protocol::SerializeType(pBuffer, &arena_battle_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
