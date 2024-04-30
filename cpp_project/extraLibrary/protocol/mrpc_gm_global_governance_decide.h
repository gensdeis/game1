#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_global_governance_decide_cs : public RpcPacket 
	{
	public:
		int32_t type{};

	public:
		mrpc_gm_global_governance_decide_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_global_governance_decide_cs, tag)
		{
		}
		mrpc_gm_global_governance_decide_cs() : RpcPacket(mpe_rpc_cmd::gm_global_governance_decide_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_global_governance_decide_sc : public RpcPacket 
	{
	public:
		int32_t type{};

	public:
		mrpc_gm_global_governance_decide_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_global_governance_decide_sc, tag)
		{
		}
		mrpc_gm_global_governance_decide_sc() : RpcPacket(mpe_rpc_cmd::gm_global_governance_decide_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
