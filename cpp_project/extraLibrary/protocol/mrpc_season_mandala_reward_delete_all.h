#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_season_mandala_reward_delete_all_cs : public RpcPacket 	// 시즌 만다라 현재시즌 이전의 모든 보상정보 삭제
	{
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		int32_t season_id{};	// 시즌 아이디

	public:
		mrpc_season_mandala_reward_delete_all_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::season_mandala_reward_delete_all_cs, tag)
		{
		}
		mrpc_season_mandala_reward_delete_all_cs() : RpcPacket(mpe_rpc_cmd::season_mandala_reward_delete_all_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &season_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_season_mandala_reward_delete_all_sc : public RpcPacket 	// 시즌 만다라 현재시즌 이전의 모든 보상정보 삭제
	{

	public:
		mrpc_season_mandala_reward_delete_all_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::season_mandala_reward_delete_all_sc, tag)
		{
		}
		mrpc_season_mandala_reward_delete_all_sc() : RpcPacket(mpe_rpc_cmd::season_mandala_reward_delete_all_sc)
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
