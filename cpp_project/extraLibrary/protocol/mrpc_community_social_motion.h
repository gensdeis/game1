#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_community_social_motion_cs : public RpcPacket 
	{
	public:
		int32_t action{};
	public:
		int64_t action_cuid{};
	public:
		std::vector<int64_t> broadcast_cuid_list{};

	public:
		mrpc_community_social_motion_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_social_motion_cs, tag)
		{
		}
		mrpc_community_social_motion_cs() : RpcPacket(mpe_rpc_cmd::community_social_motion_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &action);
			protocol::SerializeType(pBuffer, &action_cuid);
			protocol::SerializeType(pBuffer, &broadcast_cuid_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_community_social_motion_sc : public RpcPacket 
	{

	public:
		mrpc_community_social_motion_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_social_motion_sc, tag)
		{
		}
		mrpc_community_social_motion_sc() : RpcPacket(mpe_rpc_cmd::community_social_motion_sc)
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
