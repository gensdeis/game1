#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_gm_blood_dedicate_worldboss_notify_info_cs : public WebBasePacket 	// 봉혈 보스소환 및 사망 및 도주시 클라에 전달하는 메시지(gm_manager -> gm server)
	{
	public:
		mpe_blood_dedicate_worldboss_state worldboss_state{};	// 보스상태

	public:
		mweb_gm_blood_dedicate_worldboss_notify_info_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &worldboss_state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_blood_dedicate_worldboss_notify_info_sc : public WebBasePacket 	// 봉혈 보스소환 및 사망 및 도주시 클라에 전달하는 메시지(gm_manager -> gm server)
	{

	public:
		mweb_gm_blood_dedicate_worldboss_notify_info_sc() : WebBasePacket()
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
