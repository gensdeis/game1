#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_check_quest_condition_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		uint16_t quest_tid{};

	public:
		mrpc_guild_check_quest_condition_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_check_quest_condition_cs, tag)
		{
		}
		mrpc_guild_check_quest_condition_cs() : RpcPacket(mpe_rpc_cmd::guild_check_quest_condition_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &quest_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_check_quest_condition_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int32_t guild_level{};
	public:
		int32_t quest_office_level{};
	public:
		uint16_t quest_tid{};

	public:
		mrpc_guild_check_quest_condition_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_check_quest_condition_sc, tag)
		{
		}
		mrpc_guild_check_quest_condition_sc() : RpcPacket(mpe_rpc_cmd::guild_check_quest_condition_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guild_level);
			protocol::SerializeType(pBuffer, &quest_office_level);
			protocol::SerializeType(pBuffer, &quest_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
