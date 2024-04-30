#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_field_boss.h"

namespace mir3d
{
	class mrpc_gate_field_boss_regist_info_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t gid{};	// 서버 아이디

	public:
		mrpc_gate_field_boss_regist_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_field_boss_regist_info_cs, tag)
		{
		}
		mrpc_gate_field_boss_regist_info_cs() : RpcPacket(mpe_rpc_cmd::gate_field_boss_regist_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_field_boss_regist_info_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_field_boss> field_boss_list{};
	public:
		bool boss_governance_summon{};	// 보스 거버넌스 - 보스 소환 유무(false:미소환 true:소환)

	public:
		mrpc_gate_field_boss_regist_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_field_boss_regist_info_sc, tag)
		{
		}
		mrpc_gate_field_boss_regist_info_sc() : RpcPacket(mpe_rpc_cmd::gate_field_boss_regist_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &field_boss_list);
			protocol::SerializeType(pBuffer, &boss_governance_summon);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
