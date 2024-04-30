﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_member.h"

namespace mir3d
{
	class mrpc_guild_alert_join_cs : public RpcPacket 	// // 가입완료 알림 패킷 (기존문파원)
	{

	public:
		mrpc_guild_alert_join_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_join_cs, tag)
		{
		}
		mrpc_guild_alert_join_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_join_cs)
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

	class mrpc_guild_alert_join_sc : public RpcPacket 	// // 가입완료 알림 패킷 (기존문파원)
	{
	public:
		std::vector<int64_t> list_cuid{};	// // 패킷받아야할 대상
	private:
		bool flag_new_member = false;
		mps_guild_member new_member;	// // 가입처리된 유저 정보
		mps_guild_member* p_new_member = nullptr;
	public:
		bool has_new_member() const
		{
			return flag_new_member;
		}
		mps_guild_member* alloc_new_member()
		{
			flag_new_member = true;
			return &new_member;
		}
		const mps_guild_member* get_new_member() const
		{
			if (true == flag_new_member)
			{
				if (nullptr == p_new_member)
				{
					return &new_member;
				}
				return p_new_member;
			}
			return nullptr;
		}
		void set_new_member(mps_guild_member* in_new_member)
		{
			if (nullptr == p_new_member)
			{
				p_new_member = in_new_member;
				flag_new_member = true;
			}
		}

	public:
		mrpc_guild_alert_join_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_join_sc, tag)
		{
		}
		mrpc_guild_alert_join_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_join_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &flag_new_member);
			if (true == flag_new_member)
			{
				if (nullptr != p_new_member)
					protocol::SerializeType(pBuffer, p_new_member);
				else
					protocol::SerializeType(pBuffer, &new_member);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
