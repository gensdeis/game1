#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_occupationwar_owner_guild_remove_cs : public RpcPacket 
	{

	public:
		mrpc_occupationwar_owner_guild_remove_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::occupationwar_owner_guild_remove_cs, tag)
		{
		}
		mrpc_occupationwar_owner_guild_remove_cs() : RpcPacket(mpe_rpc_cmd::occupationwar_owner_guild_remove_cs)
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

	class mrpc_occupationwar_owner_guild_remove_sc : public RpcPacket 
	{
	public:
		mpe_occupationwar_map_type map_type{};
	public:
		int64_t channel_uid{};
	public:
		int32_t map_id{};

	public:
		mrpc_occupationwar_owner_guild_remove_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::occupationwar_owner_guild_remove_sc, tag)
		{
		}
		mrpc_occupationwar_owner_guild_remove_sc() : RpcPacket(mpe_rpc_cmd::occupationwar_owner_guild_remove_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &map_type);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &map_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
