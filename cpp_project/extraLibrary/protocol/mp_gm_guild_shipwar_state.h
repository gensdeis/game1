﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gm_guild_shipwar_state_cs : public BasePacket 
	{
	public:
		mpe_guild_shipwar_state state{};

	public:
		mp_gm_guild_shipwar_state_cs() : BasePacket(mpe_cmd::gm_guild_shipwar_state_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_guild_shipwar_state_sc : public BasePacket 
	{
	public:
		mpe_guild_shipwar_state state{};

	public:
		mp_gm_guild_shipwar_state_sc() : BasePacket(mpe_cmd::gm_guild_shipwar_state_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
