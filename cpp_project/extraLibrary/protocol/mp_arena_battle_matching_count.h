#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_arena_battle_matching_count_cs : public BasePacket 
	{

	public:
		mp_arena_battle_matching_count_cs() : BasePacket(mpe_cmd::arena_battle_matching_count_cs)
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

	class mp_arena_battle_matching_count_sc : public BasePacket 
	{
	public:
		int32_t remain_count{};	// 매칭 남은 유저수

	public:
		mp_arena_battle_matching_count_sc() : BasePacket(mpe_cmd::arena_battle_matching_count_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &remain_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
