﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_reward_info.h"

namespace mir3d
{
	class mp_npc_intimacy_reward_get_cs : public BasePacket 
	{

	public:
		mp_npc_intimacy_reward_get_cs() : BasePacket(mpe_cmd::npc_intimacy_reward_get_cs)
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

	class mp_npc_intimacy_reward_get_sc : public BasePacket 
	{
	public:
		std::vector<mps_reward_info> list{};

	public:
		mp_npc_intimacy_reward_get_sc() : BasePacket(mpe_cmd::npc_intimacy_reward_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
