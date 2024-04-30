﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_pr_cs : public BasePacket 
	{

	public:
		mp_guild_pr_cs() : BasePacket(mpe_cmd::guild_pr_cs)
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

	class mp_guild_pr_sc : public BasePacket 
	{
	public:
		bool result{};

	public:
		mp_guild_pr_sc() : BasePacket(mpe_cmd::guild_pr_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
