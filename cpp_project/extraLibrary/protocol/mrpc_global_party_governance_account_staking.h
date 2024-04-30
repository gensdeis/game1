#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_governance_rank.h"

namespace mir3d
{
	class mrpc_global_party_governance_account_staking_cs : public RpcPacket 	// 파티 거버넌스 유저별 스테이킹 현황
	{
	public:
		int64_t auid{};	// 계정 아이디
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		int64_t key{};	// 세션 아이디

	public:
		mrpc_global_party_governance_account_staking_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_party_governance_account_staking_cs, tag)
		{
		}
		mrpc_global_party_governance_account_staking_cs() : RpcPacket(mpe_rpc_cmd::global_party_governance_account_staking_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_global_party_governance_account_staking_sc : public RpcPacket 	// 파티 거버넌스 유저별 스테이킹 현황
	{
	public:
		std::vector<mps_party_governance_rank> account_list{};	// 계정계정 스테이킹현황
	public:
		int64_t auid{};	// 계정 아이디
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		int64_t key{};	// 세션 아이디

	public:
		mrpc_global_party_governance_account_staking_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_party_governance_account_staking_sc, tag)
		{
		}
		mrpc_global_party_governance_account_staking_sc() : RpcPacket(mpe_rpc_cmd::global_party_governance_account_staking_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &account_list);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
