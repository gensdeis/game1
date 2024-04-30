﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_community_secretvalley_alert_cs : public RpcPacket 	// 비곡점령전 맵내 알림
	{

	public:
		mrpc_community_secretvalley_alert_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_secretvalley_alert_cs, tag)
		{
		}
		mrpc_community_secretvalley_alert_cs() : RpcPacket(mpe_rpc_cmd::community_secretvalley_alert_cs)
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

	class mrpc_community_secretvalley_alert_sc : public RpcPacket 	// 비곡점령전 맵내 알림
	{
	public:
		int32_t gid{};
	public:
		int32_t message_id{};	// message id
	public:
		std::string guild_name{};	// (필요시) 문파이름
	public:
		std::string mvp_name{};	// mvp문파이름
	public:
		int32_t secretvalley_name{};	// (필요시) 비곡이름 string_id
	public:
		mpe_secretvalley_state secretvalley_state{};	// 점령전메시지상태값

	public:
		mrpc_community_secretvalley_alert_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_secretvalley_alert_sc, tag)
		{
		}
		mrpc_community_secretvalley_alert_sc() : RpcPacket(mpe_rpc_cmd::community_secretvalley_alert_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &message_id);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &mvp_name);
			protocol::SerializeType(pBuffer, &secretvalley_name);
			protocol::SerializeEnum(pBuffer, &secretvalley_state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
