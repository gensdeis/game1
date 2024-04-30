#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_gm_blood_dedicate_worldboss_notify_cs : public WebBasePacket 	// 봉혈 보스소환 및 사망 및 도주시 클라에 전달하는 메시지(world_game manager -> gm_manager)
	{
	public:
		mpe_blood_dedicate_worldboss_state worldboss_state{};	// 보스상태
	public:
		int32_t world_gid{};	// 월드 gid

	public:
		mweb_gm_blood_dedicate_worldboss_notify_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &worldboss_state);
			protocol::SerializeType(pBuffer, &world_gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_blood_dedicate_worldboss_notify_sc : public WebBasePacket 	// 봉혈 보스소환 및 사망 및 도주시 클라에 전달하는 메시지(world_game manager -> gm_manager)
	{
	public:
		mpe_error result{};	// 응답 결과

	public:
		mweb_gm_blood_dedicate_worldboss_notify_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
