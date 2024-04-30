﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_alert_learn_skill_cs : public RpcPacket 
	{

	public:
		mrpc_guild_alert_learn_skill_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_learn_skill_cs, tag)
		{
		}
		mrpc_guild_alert_learn_skill_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_learn_skill_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_alert_learn_skill_sc : public RpcPacket 
	{
	public:
		std::vector<int64_t> list_cuid{};
	public:
		int32_t old_skill_id{};
	public:
		int32_t new_skill_id{};
	public:
		int32_t guild_gold{};
	public:
		int32_t guild_blackiron{};

	public:
		mrpc_guild_alert_learn_skill_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_learn_skill_sc, tag)
		{
		}
		mrpc_guild_alert_learn_skill_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_learn_skill_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &old_skill_id);
			protocol::SerializeType(pBuffer, &new_skill_id);
			protocol::SerializeType(pBuffer, &guild_gold);
			protocol::SerializeType(pBuffer, &guild_blackiron);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
