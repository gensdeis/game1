#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gm_damage_monster_cs : public BasePacket 
	{
	public:
		int64_t uid{};	// // monster uid
	public:
		int32_t damage{};	// // damage

	public:
		mp_gm_damage_monster_cs() : BasePacket(mpe_cmd::gm_damage_monster_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &damage);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_damage_monster_sc : public BasePacket 
	{
	public:
		int64_t uid{};	// // monster uid
	public:
		int32_t damage{};	// // damage
	public:
		int32_t hp{};	// // current hp

	public:
		mp_gm_damage_monster_sc() : BasePacket(mpe_cmd::gm_damage_monster_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &damage);
			protocol::SerializeType(pBuffer, &hp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
