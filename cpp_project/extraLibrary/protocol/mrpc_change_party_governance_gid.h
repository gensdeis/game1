#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_change_party_governance_gid_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int32_t gid{};

	public:
		mrpc_change_party_governance_gid_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::change_party_governance_gid_cs, tag)
		{
		}
		mrpc_change_party_governance_gid_cs() : RpcPacket(mpe_rpc_cmd::change_party_governance_gid_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_change_party_governance_gid_sc : public RpcPacket 
	{

	public:
		mrpc_change_party_governance_gid_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::change_party_governance_gid_sc, tag)
		{
		}
		mrpc_change_party_governance_gid_sc() : RpcPacket(mpe_rpc_cmd::change_party_governance_gid_sc)
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
