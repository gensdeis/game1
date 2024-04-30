#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_dungeon_create_cs : public BasePacket 	// 문파비경 생성
	{
	public:
		int32_t dungeon_id{};

	public:
		mp_guild_dungeon_create_cs() : BasePacket(mpe_cmd::guild_dungeon_create_cs)
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

	class mp_guild_dungeon_create_sc : public BasePacket 	// 문파비경 생성
	{
	public:
		int32_t tid{};

	public:
		mp_guild_dungeon_create_sc() : BasePacket(mpe_cmd::guild_dungeon_create_sc)
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
