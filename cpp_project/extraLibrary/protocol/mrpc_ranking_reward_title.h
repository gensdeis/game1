#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_ranking_reward_title_cs : public RpcPacket 
	{

	public:
		mrpc_ranking_reward_title_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::ranking_reward_title_cs, tag)
		{
		}
		mrpc_ranking_reward_title_cs() : RpcPacket(mpe_rpc_cmd::ranking_reward_title_cs)
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

	class mrpc_ranking_reward_title_sc : public RpcPacket 
	{
	public:
		std::vector<int64_t> target_cuids{};
	public:
		std::vector<int32_t> ranks{};
	public:
		mpe_ranking_type ranking_type{};

	public:
		mrpc_ranking_reward_title_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::ranking_reward_title_sc, tag)
		{
		}
		mrpc_ranking_reward_title_sc() : RpcPacket(mpe_rpc_cmd::ranking_reward_title_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_cuids);
			protocol::SerializeType(pBuffer, &ranks);
			protocol::SerializeEnum(pBuffer, &ranking_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
