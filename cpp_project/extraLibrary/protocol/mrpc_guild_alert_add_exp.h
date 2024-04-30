#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_alert_add_exp_cs : public RpcPacket 	// // 문파 경험치 증가 알림 패킷
	{

	public:
		mrpc_guild_alert_add_exp_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_add_exp_cs, tag)
		{
		}
		mrpc_guild_alert_add_exp_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_add_exp_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_alert_add_exp_sc : public RpcPacket 	// // 문파 경험치 증가 알림 패킷
	{
	public:
		std::vector<int64_t> list_cuid{};	// // 패킷받아야할 대상
	public:
		std::string item_use_member_name{};	// // 아이템 사용한 사람
	public:
		int32_t level{};	// // 문파 레벨
	public:
		int32_t exp{};	// // 문파 경험치
	public:
		int32_t guild_gold{};	// // 문파 금전
	public:
		int32_t max_member_count{};	// // 최대 문파 인원수
	public:
		int32_t max_elder_count{};	// // 최대 장로 인원수

	public:
		mrpc_guild_alert_add_exp_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_add_exp_sc, tag)
		{
		}
		mrpc_guild_alert_add_exp_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_add_exp_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &item_use_member_name);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &exp);
			protocol::SerializeType(pBuffer, &guild_gold);
			protocol::SerializeType(pBuffer, &max_member_count);
			protocol::SerializeType(pBuffer, &max_elder_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
