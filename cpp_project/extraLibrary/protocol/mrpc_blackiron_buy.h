#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_blackiron_buy_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		uint8_t valley_type{};
	public:
		int32_t regist_key{};
	public:
		int32_t shop_id{};
	public:
		int32_t count{};
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
		mrpc_blackiron_buy_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blackiron_buy_cs, tag)
		{
		}
		mrpc_blackiron_buy_cs() : RpcPacket(mpe_rpc_cmd::blackiron_buy_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &valley_type);
			protocol::SerializeType(pBuffer, &regist_key);
			protocol::SerializeType(pBuffer, &shop_id);
			protocol::SerializeType(pBuffer, &count);
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

	class mrpc_blackiron_buy_sc : public RpcPacket 
	{
	public:
		int64_t key{};
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
		int32_t remain_blackiron_count{};

	public:
		mrpc_blackiron_buy_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blackiron_buy_sc, tag)
		{
		}
		mrpc_blackiron_buy_sc() : RpcPacket(mpe_rpc_cmd::blackiron_buy_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_update_goods);
			if (true == flag_update_goods)
			{
				if (nullptr != p_update_goods)
					protocol::SerializeType(pBuffer, p_update_goods);
				else
					protocol::SerializeType(pBuffer, &update_goods);
			}
			protocol::SerializeType(pBuffer, &remain_blackiron_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
