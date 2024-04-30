#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_api_character_item_delete_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t iuid{};

	public:
		mrpc_gm_api_character_item_delete_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_api_character_item_delete_cs, tag)
		{
		}
		mrpc_gm_api_character_item_delete_cs() : RpcPacket(mpe_rpc_cmd::gm_api_character_item_delete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &iuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_api_character_item_delete_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gm_api_character_item_delete_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_api_character_item_delete_sc, tag)
		{
		}
		mrpc_gm_api_character_item_delete_sc() : RpcPacket(mpe_rpc_cmd::gm_api_character_item_delete_sc)
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
