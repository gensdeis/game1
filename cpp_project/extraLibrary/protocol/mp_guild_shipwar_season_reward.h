﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_shipwar_season_reward_cs : public BasePacket 
	{

	public:
		mp_guild_shipwar_season_reward_cs() : BasePacket(mpe_cmd::guild_shipwar_season_reward_cs)
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

	class mp_guild_shipwar_season_reward_sc : public BasePacket 
	{

	public:
		mp_guild_shipwar_season_reward_sc() : BasePacket(mpe_cmd::guild_shipwar_season_reward_sc)
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

}
