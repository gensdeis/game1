#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_monster_phase_change_cs : public BasePacket 
	{

	public:
		mp_monster_phase_change_cs() : BasePacket(mpe_cmd::monster_phase_change_cs)
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

	class mp_monster_phase_change_sc : public BasePacket 
	{
	public:
		int64_t uid{};	// 몬스터 uid
	public:
		int32_t phase_id{};	// phase table id

	public:
		mp_monster_phase_change_sc() : BasePacket(mpe_cmd::monster_phase_change_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &phase_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
