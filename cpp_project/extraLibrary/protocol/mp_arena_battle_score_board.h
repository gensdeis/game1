#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_arena_character.h"

namespace mir3d
{
	class mp_arena_battle_score_board_cs : public BasePacket 
	{

	public:
		mp_arena_battle_score_board_cs() : BasePacket(mpe_cmd::arena_battle_score_board_cs)
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

	class mp_arena_battle_score_board_sc : public BasePacket 
	{
	public:
		std::vector<mps_arena_character> character_score{};
	public:
		int32_t a_team_count{};	// mpe_siege_team_index::def_team
	public:
		int32_t b_team_count{};	// mpe_siege_team_index::atk_team

	public:
		mp_arena_battle_score_board_sc() : BasePacket(mpe_cmd::arena_battle_score_board_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &character_score);
			protocol::SerializeType(pBuffer, &a_team_count);
			protocol::SerializeType(pBuffer, &b_team_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
