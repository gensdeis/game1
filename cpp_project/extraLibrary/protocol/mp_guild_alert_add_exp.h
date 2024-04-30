#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_alert_add_exp_cs : public BasePacket 	// // 문파 경험치 증가 알림 패킷
	{

	public:
		mp_guild_alert_add_exp_cs() : BasePacket(mpe_cmd::guild_alert_add_exp_cs)
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

	class mp_guild_alert_add_exp_sc : public BasePacket 	// // 문파 경험치 증가 알림 패킷
	{
	public:
		std::string item_use_member_name{};	// // 아이템 사용한 사람
	public:
		int32_t level{};	// // 문파 레벨
	public:
		int32_t exp{};	// // 문파 경험치
	public:
		int32_t max_member_count{};	// // 최대 문파 인원수
	public:
		int32_t max_elder_count{};	// // 최대 장로 인원수

	public:
		mp_guild_alert_add_exp_sc() : BasePacket(mpe_cmd::guild_alert_add_exp_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &item_use_member_name);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &exp);
			protocol::SerializeType(pBuffer, &max_member_count);
			protocol::SerializeType(pBuffer, &max_elder_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
