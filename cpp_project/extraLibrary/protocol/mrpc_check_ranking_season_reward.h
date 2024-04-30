#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_check_ranking_season_reward_cs : public RpcPacket 
	{
	public:
		int64_t uid{};
	public:
		int32_t gid{};
	public:
		mpe_ranking_type ranking_type{};

	public:
		mrpc_check_ranking_season_reward_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::check_ranking_season_reward_cs, tag)
		{
		}
		mrpc_check_ranking_season_reward_cs() : RpcPacket(mpe_rpc_cmd::check_ranking_season_reward_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeEnum(pBuffer, &ranking_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_check_ranking_season_reward_sc : public RpcPacket 
	{

	public:
		mrpc_check_ranking_season_reward_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::check_ranking_season_reward_sc, tag)
		{
		}
		mrpc_check_ranking_season_reward_sc() : RpcPacket(mpe_rpc_cmd::check_ranking_season_reward_sc)
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
