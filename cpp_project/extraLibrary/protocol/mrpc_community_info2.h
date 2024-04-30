#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_community_info2_cs : public RpcPacket 
	{
	public:
		mrpce_community_update_type update_type{};
	public:
		int64_t cuid{};
	public:
		int64_t value{};

	public:
		mrpc_community_info2_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_info2_cs, tag)
		{
		}
		mrpc_community_info2_cs() : RpcPacket(mpe_rpc_cmd::community_info2_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &update_type);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_community_info2_sc : public RpcPacket 
	{

	public:
		mrpc_community_info2_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_info2_sc, tag)
		{
		}
		mrpc_community_info2_sc() : RpcPacket(mpe_rpc_cmd::community_info2_sc)
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
