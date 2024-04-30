#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_monster_run_away_cs : public BasePacket 	// 몬스터 도망
	{

	public:
		mp_monster_run_away_cs() : BasePacket(mpe_cmd::monster_run_away_cs)
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

	class mp_monster_run_away_sc : public BasePacket 	// 몬스터 도망
	{
	public:
		int64_t uid{};	// 몬스터 uid
	public:
		int32_t table_id{};	// 월드보스 테이블 아이디

	public:
		mp_monster_run_away_sc() : BasePacket(mpe_cmd::monster_run_away_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &table_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
