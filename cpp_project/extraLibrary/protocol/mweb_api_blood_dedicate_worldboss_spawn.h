#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_api_blood_dedicate_worldboss_spawn_cs : public WebBasePacket 	// 봉혈 보스 강제소환[mpbs]
	{
	public:
		int32_t world_gid{};	// 월드 gid

	public:
		mweb_api_blood_dedicate_worldboss_spawn_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &world_gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_blood_dedicate_worldboss_spawn_sc : public WebBasePacket 	// 봉혈 보스 강제소환[mpbs]
	{
	public:
		mpe_error result{};	// 응답 결과

	public:
		mweb_api_blood_dedicate_worldboss_spawn_sc() : WebBasePacket()
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
