#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_info.h"

namespace mir3d
{
	class mrpc_gate_search_category_party_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<int32_t> category_list{};

	public:
		mrpc_gate_search_category_party_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_search_category_party_cs, tag)
		{
		}
		mrpc_gate_search_category_party_cs() : RpcPacket(mpe_rpc_cmd::gate_search_category_party_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &category_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_search_category_party_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_party_info> list_info{};

	public:
		mrpc_gate_search_category_party_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_search_category_party_sc, tag)
		{
		}
		mrpc_gate_search_category_party_sc() : RpcPacket(mpe_rpc_cmd::gate_search_category_party_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &list_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
