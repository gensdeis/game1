﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_alert_finish_master_order_quest_cs : public BasePacket 
	{

	public:
		mp_guild_alert_finish_master_order_quest_cs() : BasePacket(mpe_cmd::guild_alert_finish_master_order_quest_cs)
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

	class mp_guild_alert_finish_master_order_quest_sc : public BasePacket 
	{
	public:
		int32_t current_finish_member_count{};

	public:
		mp_guild_alert_finish_master_order_quest_sc() : BasePacket(mpe_cmd::guild_alert_finish_master_order_quest_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &current_finish_member_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
