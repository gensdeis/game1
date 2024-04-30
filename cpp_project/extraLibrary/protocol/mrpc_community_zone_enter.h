#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_community_zone_enter_cs : public RpcPacket 
	{

	public:
		mrpc_community_zone_enter_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_zone_enter_cs, tag)
		{
		}
		mrpc_community_zone_enter_cs() : RpcPacket(mpe_rpc_cmd::community_zone_enter_cs)
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

	class mrpc_community_zone_enter_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t channel_uid{};
	public:
		uint8_t team_index{};
	public:
		mrpce_server_type server_type{};

	public:
		mrpc_community_zone_enter_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_zone_enter_sc, tag)
		{
		}
		mrpc_community_zone_enter_sc() : RpcPacket(mpe_rpc_cmd::community_zone_enter_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &team_index);
			protocol::SerializeEnum(pBuffer, &server_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
