#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_boss_governance_server_decide_process.h"

namespace mir3d
{
	class mweb_gm_world_boss_governance_decide_info_cs : public WebBasePacket 	// 보스 거버넌스 결정정보(gmmanager_gmserver)
	{
	public:
		std::vector<mrpcs_boss_governance_server_decide_process> decide_info{};	// 서버 결정정보

	public:
		mweb_gm_world_boss_governance_decide_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &decide_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_world_boss_governance_decide_info_sc : public WebBasePacket 	// 보스 거버넌스 결정정보(gmmanager_gmserver)
	{

	public:
		mweb_gm_world_boss_governance_decide_info_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
