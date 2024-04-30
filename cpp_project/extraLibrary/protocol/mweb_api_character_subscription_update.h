#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_api_character_subscription_update_cs : public WebBasePacket 
	{
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		int32_t gid{};	// 서버 아이디
	public:
		mrpce_gm_subscription_day_type day_type{};	// 구독 활성화 일자 타입
	public:
		int32_t subscription_id{};	// 사용하고자 하는 구독 아이템 아이디

	public:
		mweb_api_character_subscription_update_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeEnum(pBuffer, &day_type);
			protocol::SerializeType(pBuffer, &subscription_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_character_subscription_update_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};	// 응답 결과

	public:
		mweb_api_character_subscription_update_sc() : WebBasePacket()
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
