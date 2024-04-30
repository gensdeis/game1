#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_community_zone_initialize_cs : public RpcPacket 
	{

	public:
		mrpc_community_zone_initialize_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_zone_initialize_cs, tag)
		{
		}
		mrpc_community_zone_initialize_cs() : RpcPacket(mpe_rpc_cmd::community_zone_initialize_cs)
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

	class mrpc_community_zone_initialize_sc : public RpcPacket 
	{
	public:
		std::vector<int64_t> list_zuid{};

	public:
		mrpc_community_zone_initialize_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_zone_initialize_sc, tag)
		{
		}
		mrpc_community_zone_initialize_sc() : RpcPacket(mpe_rpc_cmd::community_zone_initialize_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_zuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
