#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_guild_donation_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	private:
		bool flag_update_goods = false;
		mps_item_add update_goods;
		mps_item_add* p_update_goods = nullptr;
	public:
		bool has_update_goods() const
		{
			return flag_update_goods;
		}
		mps_item_add* alloc_update_goods()
		{
			flag_update_goods = true;
			return &update_goods;
		}
		const mps_item_add* get_update_goods() const
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
		void set_update_goods(mps_item_add* in_update_goods)
		{
			if (nullptr == p_update_goods)
			{
				p_update_goods = in_update_goods;
				flag_update_goods = true;
			}
		}
	public:
		mpe_guild_donation_type donation_type{};

	public:
		mrpc_guild_donation_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_donation_cs, tag)
		{
		}
		mrpc_guild_donation_cs() : RpcPacket(mpe_rpc_cmd::guild_donation_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &flag_update_goods);
			if (true == flag_update_goods)
			{
				if (nullptr != p_update_goods)
					protocol::SerializeType(pBuffer, p_update_goods);
				else
					protocol::SerializeType(pBuffer, &update_goods);
			}
			protocol::SerializeEnum(pBuffer, &donation_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_donation_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	private:
		bool flag_update_goods = false;
		mps_item_add update_goods;
		mps_item_add* p_update_goods = nullptr;
	public:
		bool has_update_goods() const
		{
			return flag_update_goods;
		}
		mps_item_add* alloc_update_goods()
		{
			flag_update_goods = true;
			return &update_goods;
		}
		const mps_item_add* get_update_goods() const
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
		void set_update_goods(mps_item_add* in_update_goods)
		{
			if (nullptr == p_update_goods)
			{
				p_update_goods = in_update_goods;
				flag_update_goods = true;
			}
		}
	public:
		int32_t donation_count{};
	public:
		mpe_guild_donation_type donation_type{};
	public:
		int32_t available_time{};

	public:
		mrpc_guild_donation_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_donation_sc, tag)
		{
		}
		mrpc_guild_donation_sc() : RpcPacket(mpe_rpc_cmd::guild_donation_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_update_goods);
			if (true == flag_update_goods)
			{
				if (nullptr != p_update_goods)
					protocol::SerializeType(pBuffer, p_update_goods);
				else
					protocol::SerializeType(pBuffer, &update_goods);
			}
			protocol::SerializeType(pBuffer, &donation_count);
			protocol::SerializeEnum(pBuffer, &donation_type);
			protocol::SerializeType(pBuffer, &available_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
