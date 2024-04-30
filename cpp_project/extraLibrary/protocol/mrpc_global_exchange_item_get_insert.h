#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_global_exchange_item_get_insert_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int64_t euid{};
	public:
		mpe_cmd request_cmd{};
	public:
		mpe_exchange_type type{};
	private:
		bool flag_item = false;
		mps_item_add item;
		mps_item_add* p_item = nullptr;
	public:
		bool has_item() const
		{
			return flag_item;
		}
		mps_item_add* alloc_item()
		{
			flag_item = true;
			return &item;
		}
		const mps_item_add* get_item() const
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
		void set_item(mps_item_add* in_item)
		{
			if (nullptr == p_item)
			{
				p_item = in_item;
				flag_item = true;
			}
		}
	public:
		int64_t socket_access_token{};

	public:
		mrpc_global_exchange_item_get_insert_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_exchange_item_get_insert_cs, tag)
		{
		}
		mrpc_global_exchange_item_get_insert_cs() : RpcPacket(mpe_rpc_cmd::global_exchange_item_get_insert_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeEnum(pBuffer, &request_cmd);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &flag_item);
			if (true == flag_item)
			{
				if (nullptr != p_item)
					protocol::SerializeType(pBuffer, p_item);
				else
					protocol::SerializeType(pBuffer, &item);
			}
			protocol::SerializeType(pBuffer, &socket_access_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_global_exchange_item_get_insert_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int64_t euid{};
	public:
		mpe_cmd request_cmd{};
	public:
		mpe_exchange_type type{};
	private:
		bool flag_item = false;
		mps_item_add item;
		mps_item_add* p_item = nullptr;
	public:
		bool has_item() const
		{
			return flag_item;
		}
		mps_item_add* alloc_item()
		{
			flag_item = true;
			return &item;
		}
		const mps_item_add* get_item() const
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
		void set_item(mps_item_add* in_item)
		{
			if (nullptr == p_item)
			{
				p_item = in_item;
				flag_item = true;
			}
		}

	public:
		mrpc_global_exchange_item_get_insert_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_exchange_item_get_insert_sc, tag)
		{
		}
		mrpc_global_exchange_item_get_insert_sc() : RpcPacket(mpe_rpc_cmd::global_exchange_item_get_insert_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeEnum(pBuffer, &request_cmd);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &flag_item);
			if (true == flag_item)
			{
				if (nullptr != p_item)
					protocol::SerializeType(pBuffer, p_item);
				else
					protocol::SerializeType(pBuffer, &item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
