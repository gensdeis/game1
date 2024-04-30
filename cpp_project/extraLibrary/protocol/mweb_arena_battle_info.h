#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_arena_battle_info_cs : public WebBasePacket 	// gate에서 삭제
	{
	public:
		int64_t cuid{};
	public:
		int32_t gid{};

	public:
		mweb_arena_battle_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_arena_battle_info_sc : public WebBasePacket 	// gate에서 삭제
	{
	public:
		uint16_t season{};	// 현재 시즌
	public:
		uint16_t round{};	// 현재 회차
	public:
		int32_t rank{};
	public:
		int32_t score{};
	public:
		uint16_t last_round{};	// 내가 참여한 마지막회차
	public:
		uint8_t join_count{};	// last_round 회차에서 참여한 횟수
	public:
		bool is_new_season{};	// 새 시즌인 경우 true
	public:
		int32_t prev_season_reward_tid{};	// 전 시즌 보상 받을것 있는경우 arena_ranking_table id

	public:
		mweb_arena_battle_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &season);
			protocol::SerializeType(pBuffer, &round);
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &score);
			protocol::SerializeType(pBuffer, &last_round);
			protocol::SerializeType(pBuffer, &join_count);
			protocol::SerializeType(pBuffer, &is_new_season);
			protocol::SerializeType(pBuffer, &prev_season_reward_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
