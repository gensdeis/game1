#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods_list.h"
#include "struct/mps_wanted_murder_register_info.h"
#include "struct/mps_update_goods_list.h"

namespace mir3d
{
	class mrpc_wanted_murder_register_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t record_id{};
	public:
		int64_t register_cuid{};
	public:
		int64_t target_cuid{};
	public:
		int32_t reward_value{};
	public:
		int32_t shop_tid{};
	private:
		bool flag_update_goods = false;
		mps_update_goods_list update_goods;
		mps_update_goods_list* p_update_goods = nullptr;
	public:
		bool has_update_goods() const
		{
			return flag_update_goods;
		}
		mps_update_goods_list* alloc_update_goods()
		{
			flag_update_goods = true;
			return &update_goods;
		}
		const mps_update_goods_list* get_update_goods() const
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
		void set_update_goods(mps_update_goods_list* in_update_goods)
		{
			if (nullptr == p_update_goods)
			{
				p_update_goods = in_update_goods;
				flag_update_goods = true;
			}
		}
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mrpc_wanted_murder_register_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::wanted_murder_register_cs, tag)
		{
		}
		mrpc_wanted_murder_register_cs() : RpcPacket(mpe_rpc_cmd::wanted_murder_register_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &record_id);
			protocol::SerializeType(pBuffer, &register_cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &reward_value);
			protocol::SerializeType(pBuffer, &shop_tid);
			protocol::SerializeType(pBuffer, &flag_update_goods);
			if (true == flag_update_goods)
			{
				if (nullptr != p_update_goods)
					protocol::SerializeType(pBuffer, p_update_goods);
				else
					protocol::SerializeType(pBuffer, &update_goods);
			}
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_wanted_murder_register_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t record_id{};
	private:
		bool flag_info = false;
		mps_wanted_murder_register_info info;
		mps_wanted_murder_register_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_wanted_murder_register_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_wanted_murder_register_info* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mps_wanted_murder_register_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	private:
		bool flag_update_goods = false;
		mps_update_goods_list update_goods;
		mps_update_goods_list* p_update_goods = nullptr;
	public:
		bool has_update_goods() const
		{
			return flag_update_goods;
		}
		mps_update_goods_list* alloc_update_goods()
		{
			flag_update_goods = true;
			return &update_goods;
		}
		const mps_update_goods_list* get_update_goods() const
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
		void set_update_goods(mps_update_goods_list* in_update_goods)
		{
			if (nullptr == p_update_goods)
			{
				p_update_goods = in_update_goods;
				flag_update_goods = true;
			}
		}

	public:
		mrpc_wanted_murder_register_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::wanted_murder_register_sc, tag)
		{
		}
		mrpc_wanted_murder_register_sc() : RpcPacket(mpe_rpc_cmd::wanted_murder_register_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &record_id);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
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
