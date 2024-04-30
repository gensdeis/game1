﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_season_mandala_reward_delete_cs : public RpcPacket 	// 시즌 만다라 현재보상 정보삭제
	{
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		std::vector<int32_t> delete_list{};	// 삭제 대상이되는 테이블 아이디

	public:
		mrpc_season_mandala_reward_delete_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::season_mandala_reward_delete_cs, tag)
		{
		}
		mrpc_season_mandala_reward_delete_cs() : RpcPacket(mpe_rpc_cmd::season_mandala_reward_delete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &delete_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_season_mandala_reward_delete_sc : public RpcPacket 	// 시즌 만다라 현재보상 정보삭제
	{

	public:
		mrpc_season_mandala_reward_delete_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::season_mandala_reward_delete_sc, tag)
		{
		}
		mrpc_season_mandala_reward_delete_sc() : RpcPacket(mpe_rpc_cmd::season_mandala_reward_delete_sc)
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
