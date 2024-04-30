#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_arena_battle_alert_cs : public BasePacket 
	{

	public:
		mp_arena_battle_alert_cs() : BasePacket(mpe_cmd::arena_battle_alert_cs)
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

	class mp_arena_battle_alert_sc : public BasePacket 
	{
	public:
		mpe_arena_battle_alert alert_cmd{};	// 배틀 알림
	public:
		uint8_t win_team{};	// 종료 시 승리팀정보
	public:
		std::vector<int64_t> list_mvp{};

	public:
		mp_arena_battle_alert_sc() : BasePacket(mpe_cmd::arena_battle_alert_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &alert_cmd);
			protocol::SerializeType(pBuffer, &win_team);
			protocol::SerializeType(pBuffer, &list_mvp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
