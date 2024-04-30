﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods.h"

namespace mir3d
{
	class mrpc_mentor_buff_buy_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t buff_id{};
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
		mrpc_mentor_buff_buy_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mentor_buff_buy_cs, tag)
		{
		}
		mrpc_mentor_buff_buy_cs() : RpcPacket(mpe_rpc_cmd::mentor_buff_buy_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &buff_id);
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

	class mrpc_mentor_buff_buy_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_mentor_buff_buy_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::mentor_buff_buy_sc, tag)
		{
		}
		mrpc_mentor_buff_buy_sc() : RpcPacket(mpe_rpc_cmd::mentor_buff_buy_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}