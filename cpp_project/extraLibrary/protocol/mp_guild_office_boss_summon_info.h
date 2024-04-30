#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_office_boss_summon_info_cs : public BasePacket 
	{

	public:
		mp_guild_office_boss_summon_info_cs() : BasePacket(mpe_cmd::guild_office_boss_summon_info_cs)
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

	class mp_guild_office_boss_summon_info_sc : public BasePacket 
	{
	public:
		std::vector<int32_t> list_item_id{};	// 소환석 리스트
	public:
		int32_t cur_stage{};	// 현재 진행중인 소환석
	public:
		int32_t use_item_count{};	// 누적 소환석 사용량
	public:
		int64_t end_time{};	// 끝나는 시간

	public:
		mp_guild_office_boss_summon_info_sc() : BasePacket(mpe_cmd::guild_office_boss_summon_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_item_id);
			protocol::SerializeType(pBuffer, &cur_stage);
			protocol::SerializeType(pBuffer, &use_item_count);
			protocol::SerializeType(pBuffer, &end_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
