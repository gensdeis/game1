#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_field_boss.h"

namespace mir3d
{
	class mp_gate_field_boss_regist_info_cs : public BasePacket 
	{
	public:
		int32_t gid{};	// 서버 아이디

	public:
		mp_gate_field_boss_regist_info_cs() : BasePacket(mpe_cmd::gate_field_boss_regist_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_field_boss_regist_info_sc : public BasePacket 
	{
	public:
		std::vector<mps_field_boss> field_boss_list{};
	public:
		bool boss_governance_summon{};	// 보스 거버넌스 - 보스 소환 유무(false:미소환 true:소환)

	public:
		mp_gate_field_boss_regist_info_sc() : BasePacket(mpe_cmd::gate_field_boss_regist_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &field_boss_list);
			protocol::SerializeType(pBuffer, &boss_governance_summon);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
