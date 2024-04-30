#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_dungeon_enter_charge_cs : public BasePacket 
	{
	public:
		int32_t dungeon_id{};

	public:
		mp_guild_dungeon_enter_charge_cs() : BasePacket(mpe_cmd::guild_dungeon_enter_charge_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &dungeon_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_dungeon_enter_charge_sc : public BasePacket 
	{
	public:
		int32_t tid{};

	public:
		mp_guild_dungeon_enter_charge_sc() : BasePacket(mpe_cmd::guild_dungeon_enter_charge_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
