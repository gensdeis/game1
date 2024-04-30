#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_war.h"

namespace mir3d
{
	class mrpc_guild_alert_start_war_cs : public RpcPacket 	// // 전쟁 선포 알림 패킷
	{

	public:
		mrpc_guild_alert_start_war_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_start_war_cs, tag)
		{
		}
		mrpc_guild_alert_start_war_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_start_war_cs)
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

	class mrpc_guild_alert_start_war_sc : public RpcPacket 	// // 전쟁 선포 알림 패킷
	{
	public:
		std::vector<int64_t> list_cuid{};	// // 패킷받아야할 대상
	private:
		bool flag_war = false;
		mps_guild_war war;	// // 전쟁 정보
		mps_guild_war* p_war = nullptr;
	public:
		bool has_war() const
		{
			return flag_war;
		}
		mps_guild_war* alloc_war()
		{
			flag_war = true;
			return &war;
		}
		const mps_guild_war* get_war() const
		{
			if (true == flag_war)
			{
				if (nullptr == p_war)
				{
					return &war;
				}
				return p_war;
			}
			return nullptr;
		}
		void set_war(mps_guild_war* in_war)
		{
			if (nullptr == p_war)
			{
				p_war = in_war;
				flag_war = true;
			}
		}

	public:
		mrpc_guild_alert_start_war_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_start_war_sc, tag)
		{
		}
		mrpc_guild_alert_start_war_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_start_war_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &flag_war);
			if (true == flag_war)
			{
				if (nullptr != p_war)
					protocol::SerializeType(pBuffer, p_war);
				else
					protocol::SerializeType(pBuffer, &war);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
