#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_contents_onoff_list.h"

namespace mir3d
{
	class mrpc_gate_contents_onoff_list_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<int32_t> list_type{};	// List<mpe_contents_onoff_type>

	public:
		mrpc_gate_contents_onoff_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_contents_onoff_list_cs, tag)
		{
		}
		mrpc_gate_contents_onoff_list_cs() : RpcPacket(mpe_rpc_cmd::gate_contents_onoff_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &list_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_contents_onoff_list_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_contents_onoff_list> list{};

	public:
		mrpc_gate_contents_onoff_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_contents_onoff_list_sc, tag)
		{
		}
		mrpc_gate_contents_onoff_list_sc() : RpcPacket(mpe_rpc_cmd::gate_contents_onoff_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
