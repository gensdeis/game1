#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_field_boss.h"

namespace mir3d
{
	class mweb_field_boss_regist_info_cs : public WebBasePacket 
	{
	public:
		int32_t gid{};	// 서버 아이디

	public:
		mweb_field_boss_regist_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_field_boss_regist_info_sc : public WebBasePacket 
	{
	public:
		std::vector<mps_field_boss> field_boss_list{};
	public:
		bool boss_governance_summon{};	// 보스 거버넌스 - 보스 소환 유무(false:미소환 true:소환)

	public:
		mweb_field_boss_regist_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &field_boss_list);
			protocol::SerializeType(pBuffer, &boss_governance_summon);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
