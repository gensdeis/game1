#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_debug_print_rpcinfo_cs : public RpcPacket 	// 디버깅용패킷
	{
	public:
		int64_t key{};

	public:
		mrpc_debug_print_rpcinfo_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::debug_print_rpcinfo_cs, tag)
		{
		}
		mrpc_debug_print_rpcinfo_cs() : RpcPacket(mpe_rpc_cmd::debug_print_rpcinfo_cs)
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

	class mrpc_debug_print_rpcinfo_sc : public RpcPacket 	// 디버깅용패킷
	{
	public:
		int64_t key{};

	public:
		mrpc_debug_print_rpcinfo_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::debug_print_rpcinfo_sc, tag)
		{
		}
		mrpc_debug_print_rpcinfo_sc() : RpcPacket(mpe_rpc_cmd::debug_print_rpcinfo_sc)
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
