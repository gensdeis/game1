#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item.h"

namespace mir3d
{
	class mrpc_guild_storage_material_list_cs : public RpcPacket 	// 문파 재료 창고 조회
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};

	public:
		mrpc_guild_storage_material_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_material_list_cs, tag)
		{
		}
		mrpc_guild_storage_material_list_cs() : RpcPacket(mpe_rpc_cmd::guild_storage_material_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_storage_material_list_sc : public RpcPacket 	// 문파 재료 창고 조회
	{
	public:
		int64_t cuid{};
	public:
		std::vector<mps_item> list_item{};
	public:
		uint8_t item_donation_count{};

	public:
		mrpc_guild_storage_material_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_material_list_sc, tag)
		{
		}
		mrpc_guild_storage_material_list_sc() : RpcPacket(mpe_rpc_cmd::guild_storage_material_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &list_item);
			protocol::SerializeType(pBuffer, &item_donation_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
