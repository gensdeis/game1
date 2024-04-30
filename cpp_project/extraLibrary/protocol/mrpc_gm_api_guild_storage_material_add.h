#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_api_guild_storage_material_add_cs : public RpcPacket 
	{
	public:
		int64_t guid{};
	public:
		int32_t item_tid{};
	public:
		int32_t count{};
	public:
		int64_t key{};	// gm server key

	public:
		mrpc_gm_api_guild_storage_material_add_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_api_guild_storage_material_add_cs, tag)
		{
		}
		mrpc_gm_api_guild_storage_material_add_cs() : RpcPacket(mpe_rpc_cmd::gm_api_guild_storage_material_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &item_tid);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_api_guild_storage_material_add_sc : public RpcPacket 
	{
	public:
		int64_t key{};	// gm server key

	public:
		mrpc_gm_api_guild_storage_material_add_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_api_guild_storage_material_add_sc, tag)
		{
		}
		mrpc_gm_api_guild_storage_material_add_sc() : RpcPacket(mpe_rpc_cmd::gm_api_guild_storage_material_add_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
