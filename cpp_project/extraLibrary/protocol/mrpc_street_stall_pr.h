#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_street_stall_pr_cs : public RpcPacket 
	{
	public:
		int32_t map_id{};
	public:
		int32_t channel_id{};
	public:
		std::string character_name{};
	public:
		std::string street_stall_title{};
	public:
		int32_t gid{};

	public:
		mrpc_street_stall_pr_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::street_stall_pr_cs, tag)
		{
		}
		mrpc_street_stall_pr_cs() : RpcPacket(mpe_rpc_cmd::street_stall_pr_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &map_id);
			protocol::SerializeType(pBuffer, &channel_id);
			protocol::SerializeType(pBuffer, &character_name);
			protocol::SerializeType(pBuffer, &street_stall_title);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_street_stall_pr_sc : public RpcPacket 
	{

	public:
		mrpc_street_stall_pr_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::street_stall_pr_sc, tag)
		{
		}
		mrpc_street_stall_pr_sc() : RpcPacket(mpe_rpc_cmd::street_stall_pr_sc)
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
