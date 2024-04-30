#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_global_governance_command_cs : public RpcPacket 
	{

	public:
		mrpc_gm_global_governance_command_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_global_governance_command_cs, tag)
		{
		}
		mrpc_gm_global_governance_command_cs() : RpcPacket(mpe_rpc_cmd::gm_global_governance_command_cs)
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

	class mrpc_gm_global_governance_command_sc : public RpcPacket 
	{
	public:
		mpe_governance_contents_type contents_type{};
	public:
		mrpce_global_governance_command_type command_type{};
	public:
		int64_t cuid{};
	public:
		int32_t count{};

	public:
		mrpc_gm_global_governance_command_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_global_governance_command_sc, tag)
		{
		}
		mrpc_gm_global_governance_command_sc() : RpcPacket(mpe_rpc_cmd::gm_global_governance_command_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &contents_type);
			protocol::SerializeEnum(pBuffer, &command_type);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
