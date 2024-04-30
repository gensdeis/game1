#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_boss_dungeon_start_time_cs : public BasePacket 	// 보스던전 시작시간 동기화 패킷
	{

	public:
		mp_boss_dungeon_start_time_cs() : BasePacket(mpe_cmd::boss_dungeon_start_time_cs)
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

	class mp_boss_dungeon_start_time_sc : public BasePacket 	// 보스던전 시작시간 동기화 패킷
	{
	public:
		int64_t start_time{};	// 시작 시간 (UTC msec)

	public:
		mp_boss_dungeon_start_time_sc() : BasePacket(mpe_cmd::boss_dungeon_start_time_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &start_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
