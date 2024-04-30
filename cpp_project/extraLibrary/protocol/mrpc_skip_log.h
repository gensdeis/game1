#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_skip_log_cs : public RpcPacket 
	{

	public:
		mrpc_skip_log_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::skip_log_cs, tag)
		{
		}
		mrpc_skip_log_cs() : RpcPacket(mpe_rpc_cmd::skip_log_cs)
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

	class mrpc_skip_log_sc : public RpcPacket 
	{

	public:
		mrpc_skip_log_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::skip_log_sc, tag)
		{
		}
		mrpc_skip_log_sc() : RpcPacket(mpe_rpc_cmd::skip_log_sc)
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
