#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_community_zone_create_cs : public RpcPacket 
	{

	public:
		mrpc_community_zone_create_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_zone_create_cs, tag)
		{
		}
		mrpc_community_zone_create_cs() : RpcPacket(mpe_rpc_cmd::community_zone_create_cs)
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

	class mrpc_community_zone_create_sc : public RpcPacket 
	{
	public:
		int64_t zuid{};
	public:
		bool flag{};	// false : delete, true : create

	public:
		mrpc_community_zone_create_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_zone_create_sc, tag)
		{
		}
		mrpc_community_zone_create_sc() : RpcPacket(mpe_rpc_cmd::community_zone_create_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &zuid);
			protocol::SerializeType(pBuffer, &flag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
