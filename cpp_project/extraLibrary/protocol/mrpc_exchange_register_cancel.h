#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_exchange_context.h"
#include "struct/mps_item.h"
#include "struct/mrpcs_item_stone_pair.h"

namespace mir3d
{
	class mrpc_exchange_register_cancel_cs : public RpcPacket 
	{
	private:
		bool flag_info = false;
		mrpcs_exchange_context info;
		mrpcs_exchange_context* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_exchange_context* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_exchange_context* get_info() const
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
		void set_info(mrpcs_exchange_context* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int64_t socket_access_token{};

	public:
		mrpc_exchange_register_cancel_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::exchange_register_cancel_cs, tag)
		{
		}
		mrpc_exchange_register_cancel_cs() : RpcPacket(mpe_rpc_cmd::exchange_register_cancel_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &socket_access_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_exchange_register_cancel_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t euid{};
	public:
		int64_t cuid{};
	public:
		uint8_t type{};	// // 0 : normal, 1 : world
	private:
		bool flag_item = false;
		mps_item item;
		mps_item* p_item = nullptr;
	public:
		bool has_item() const
		{
			return flag_item;
		}
		mps_item* alloc_item()
		{
			flag_item = true;
			return &item;
		}
		const mps_item* get_item() const
		{
			if (true == flag_item)
			{
				if (nullptr == p_item)
				{
					return &item;
				}
				return p_item;
			}
			return nullptr;
		}
		void set_item(mps_item* in_item)
		{
			if (nullptr == p_item)
			{
				p_item = in_item;
				flag_item = true;
			}
		}
	private:
		bool flag_stone_pair = false;
		mrpcs_item_stone_pair stone_pair;	// 용령석 연결 정보
		mrpcs_item_stone_pair* p_stone_pair = nullptr;
	public:
		bool has_stone_pair() const
		{
			return flag_stone_pair;
		}
		mrpcs_item_stone_pair* alloc_stone_pair()
		{
			flag_stone_pair = true;
			return &stone_pair;
		}
		const mrpcs_item_stone_pair* get_stone_pair() const
		{
			if (true == flag_stone_pair)
			{
				if (nullptr == p_stone_pair)
				{
					return &stone_pair;
				}
				return p_stone_pair;
			}
			return nullptr;
		}
		void set_stone_pair(mrpcs_item_stone_pair* in_stone_pair)
		{
			if (nullptr == p_stone_pair)
			{
				p_stone_pair = in_stone_pair;
				flag_stone_pair = true;
			}
		}

	public:
		mrpc_exchange_register_cancel_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::exchange_register_cancel_sc, tag)
		{
		}
		mrpc_exchange_register_cancel_sc() : RpcPacket(mpe_rpc_cmd::exchange_register_cancel_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &flag_item);
			if (true == flag_item)
			{
				if (nullptr != p_item)
					protocol::SerializeType(pBuffer, p_item);
				else
					protocol::SerializeType(pBuffer, &item);
			}
			protocol::SerializeType(pBuffer, &flag_stone_pair);
			if (true == flag_stone_pair)
			{
				if (nullptr != p_stone_pair)
					protocol::SerializeType(pBuffer, p_stone_pair);
				else
					protocol::SerializeType(pBuffer, &stone_pair);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
