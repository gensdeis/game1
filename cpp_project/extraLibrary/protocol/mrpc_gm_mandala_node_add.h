#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mandala_node_info.h"

namespace mir3d
{
	class mrpc_gm_mandala_node_add_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		mpe_mandala_type type{};
	public:
		std::vector<mps_mandala_node_info> list_node{};

	public:
		mrpc_gm_mandala_node_add_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_mandala_node_add_cs, tag)
		{
		}
		mrpc_gm_mandala_node_add_cs() : RpcPacket(mpe_rpc_cmd::gm_mandala_node_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &list_node);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_mandala_node_add_sc : public RpcPacket 
	{

	public:
		mrpc_gm_mandala_node_add_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_mandala_node_add_sc, tag)
		{
		}
		mrpc_gm_mandala_node_add_sc() : RpcPacket(mpe_rpc_cmd::gm_mandala_node_add_sc)
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
