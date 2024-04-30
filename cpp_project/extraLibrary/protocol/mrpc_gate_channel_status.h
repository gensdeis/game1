#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_channel_status_info.h"

namespace mir3d
{
	class mrpc_gate_channel_status_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t map_id{};

	public:
		mrpc_gate_channel_status_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_channel_status_cs, tag)
		{
		}
		mrpc_gate_channel_status_cs() : RpcPacket(mpe_rpc_cmd::gate_channel_status_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &map_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_channel_status_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_channel_status_info> channel_info_list{};

	public:
		mrpc_gate_channel_status_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_channel_status_sc, tag)
		{
		}
		mrpc_gate_channel_status_sc() : RpcPacket(mpe_rpc_cmd::gate_channel_status_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &channel_info_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
