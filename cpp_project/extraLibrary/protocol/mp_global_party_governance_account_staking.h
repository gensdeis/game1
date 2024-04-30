#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_governance_rank.h"

namespace mir3d
{
	class mp_global_party_governance_account_staking_cs : public BasePacket 	// 계정 스테이킹현황
	{

	public:
		mp_global_party_governance_account_staking_cs() : BasePacket(mpe_cmd::global_party_governance_account_staking_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_global_party_governance_account_staking_sc : public BasePacket 	// 계정 스테이킹현황
	{
	public:
		std::vector<mps_party_governance_rank> account_list{};	// 계정 스테이킹현황
	public:
		mpe_error result{};	// 응답결과

	public:
		mp_global_party_governance_account_staking_sc() : BasePacket(mpe_cmd::global_party_governance_account_staking_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &account_list);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
