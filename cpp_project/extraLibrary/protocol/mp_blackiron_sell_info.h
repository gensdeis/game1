#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_id.h"

namespace mir3d
{
	class mp_blackiron_sell_info_cs : public BasePacket 
	{
	public:
		int64_t nuid{};	// npc uid

	public:
		mp_blackiron_sell_info_cs() : BasePacket(mpe_cmd::blackiron_sell_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_blackiron_sell_info_sc : public BasePacket 
	{
	public:
		std::vector<mps_item_id> sell_list{};	// 판매정보
	public:
		int32_t sell_end_time{};	// 판매종료 시간
	public:
		int32_t sell_regist_key{};	// 판매등록 키값
	public:
		int32_t sell_total_count{};	// 판매량
	public:
		std::string guild_name{};	// 점령중인문파이름
	public:
		std::vector<uint8_t> guild_mark{};	// 점령중인문파문장

	public:
		mp_blackiron_sell_info_sc() : BasePacket(mpe_cmd::blackiron_sell_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &sell_list);
			protocol::SerializeType(pBuffer, &sell_end_time);
			protocol::SerializeType(pBuffer, &sell_regist_key);
			protocol::SerializeType(pBuffer, &sell_total_count);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &guild_mark);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
