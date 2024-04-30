#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_shipwar_get_reward_cs : public RpcPacket 
	{
	public:
		int64_t guid{};
	public:
		int32_t value{};	// 재화 수치
	public:
		mpe_guild_donation_type type{};	// 재화 타입

	public:
		mrpc_guild_shipwar_get_reward_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_shipwar_get_reward_cs, tag)
		{
		}
		mrpc_guild_shipwar_get_reward_cs() : RpcPacket(mpe_rpc_cmd::guild_shipwar_get_reward_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &value);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_shipwar_get_reward_sc : public RpcPacket 
	{

	public:
		mrpc_guild_shipwar_get_reward_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_shipwar_get_reward_sc, tag)
		{
		}
		mrpc_guild_shipwar_get_reward_sc() : RpcPacket(mpe_rpc_cmd::guild_shipwar_get_reward_sc)
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

}
