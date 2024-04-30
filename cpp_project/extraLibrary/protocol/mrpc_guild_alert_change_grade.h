﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_alert_change_grade_cs : public RpcPacket 	// // 문파원 계급 변경 알림 패킷
	{

	public:
		mrpc_guild_alert_change_grade_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_change_grade_cs, tag)
		{
		}
		mrpc_guild_alert_change_grade_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_change_grade_cs)
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

	class mrpc_guild_alert_change_grade_sc : public RpcPacket 	// // 문파원 계급 변경 알림 패킷
	{
	public:
		std::vector<int64_t> list_cuid{};	// // 패킷받아야할 대상
	public:
		int64_t change_member_cuid{};	// // 변경된 유저ID
	public:
		std::string change_member_name{};	// // 변경된 유저명
	public:
		mpe_guild_member_grade new_grade{};	// // 변경된 계급

	public:
		mrpc_guild_alert_change_grade_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_change_grade_sc, tag)
		{
		}
		mrpc_guild_alert_change_grade_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_change_grade_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &change_member_cuid);
			protocol::SerializeType(pBuffer, &change_member_name);
			protocol::SerializeEnum(pBuffer, &new_grade);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}