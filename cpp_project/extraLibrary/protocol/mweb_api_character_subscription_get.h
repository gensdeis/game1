#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_gm_subscription_info.h"

namespace mir3d
{
	class mweb_api_character_subscription_get_cs : public WebBasePacket 
	{
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		int32_t gid{};	// 서버 아이디

	public:
		mweb_api_character_subscription_get_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_character_subscription_get_sc : public WebBasePacket 
	{
	public:
		std::vector<mrpcs_gm_subscription_info> info{};	// 캐릭터 구독서비스 정보
	public:
		mpe_error result{};	// 응답 결과

	public:
		mweb_api_character_subscription_get_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
