#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods.h"

namespace mir3d
{
	class mrpc_guild_alert_donation_cs : public RpcPacket 
	{

	public:
		mrpc_guild_alert_donation_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_donation_cs, tag)
		{
		}
		mrpc_guild_alert_donation_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_donation_cs)
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

	class mrpc_guild_alert_donation_sc : public RpcPacket 
	{
	public:
		std::vector<int64_t> list_cuid{};
	public:
		int64_t donate_member_cuid{};
	public:
		std::string donate_member_name{};
	public:
		int32_t update_guild_point{};
	public:
		int32_t used_gold{};
	private:
		bool flag_update_goods = false;
		mps_update_goods update_goods;
		mps_update_goods* p_update_goods = nullptr;
	public:
		bool has_update_goods() const
		{
			return flag_update_goods;
		}
		mps_update_goods* alloc_update_goods()
		{
			flag_update_goods = true;
			return &update_goods;
		}
		const mps_update_goods* get_update_goods() const
		{
			if (true == flag_update_goods)
			{
				if (nullptr == p_update_goods)
				{
					return &update_goods;
				}
				return p_update_goods;
			}
			return nullptr;
		}
		void set_update_goods(mps_update_goods* in_update_goods)
		{
			if (nullptr == p_update_goods)
			{
				p_update_goods = in_update_goods;
				flag_update_goods = true;
			}
		}

	public:
		mrpc_guild_alert_donation_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_donation_sc, tag)
		{
		}
		mrpc_guild_alert_donation_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_donation_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &donate_member_cuid);
			protocol::SerializeType(pBuffer, &donate_member_name);
			protocol::SerializeType(pBuffer, &update_guild_point);
			protocol::SerializeType(pBuffer, &used_gold);
			protocol::SerializeType(pBuffer, &flag_update_goods);
			if (true == flag_update_goods)
			{
				if (nullptr != p_update_goods)
					protocol::SerializeType(pBuffer, p_update_goods);
				else
					protocol::SerializeType(pBuffer, &update_goods);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
