#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_guildshipwar_season_reward_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};

	public:
		mrpc_gate_guildshipwar_season_reward_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_guildshipwar_season_reward_cs, tag)
		{
		}
		mrpc_gate_guildshipwar_season_reward_cs() : RpcPacket(mpe_rpc_cmd::gate_guildshipwar_season_reward_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_guildshipwar_season_reward_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		bool isReward{};
	public:
		bool is_new_season{};
	public:
		int32_t season{};	// 현재시즌
	public:
		int32_t rank{};	// 이전시즌 순위
	public:
		int32_t league{};	// 이전시즌 리그

	public:
		mrpc_gate_guildshipwar_season_reward_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_guildshipwar_season_reward_sc, tag)
		{
		}
		mrpc_gate_guildshipwar_season_reward_sc() : RpcPacket(mpe_rpc_cmd::gate_guildshipwar_season_reward_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &isReward);
			protocol::SerializeType(pBuffer, &is_new_season);
			protocol::SerializeType(pBuffer, &season);
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &league);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
