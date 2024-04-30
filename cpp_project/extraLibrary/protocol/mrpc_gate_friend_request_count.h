#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_friend_request_count_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};

	public:
		mrpc_gate_friend_request_count_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_friend_request_count_cs, tag)
		{
		}
		mrpc_gate_friend_request_count_cs() : RpcPacket(mpe_rpc_cmd::gate_friend_request_count_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_friend_request_count_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t request_count{};

	public:
		mrpc_gate_friend_request_count_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_friend_request_count_sc, tag)
		{
		}
		mrpc_gate_friend_request_count_sc() : RpcPacket(mpe_rpc_cmd::gate_friend_request_count_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &request_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
