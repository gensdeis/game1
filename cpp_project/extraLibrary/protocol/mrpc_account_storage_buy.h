#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods.h"
#include "struct/mps_account_storage.h"
#include "struct/mps_update_goods.h"
#include "struct/mps_inventory.h"

namespace mir3d
{
	class mrpc_account_storage_buy_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	private:
		bool flag_goods_info = false;
		mps_update_goods goods_info;
		mps_update_goods* p_goods_info = nullptr;
	public:
		bool has_goods_info() const
		{
			return flag_goods_info;
		}
		mps_update_goods* alloc_goods_info()
		{
			flag_goods_info = true;
			return &goods_info;
		}
		const mps_update_goods* get_goods_info() const
		{
			if (true == flag_goods_info)
			{
				if (nullptr == p_goods_info)
				{
					return &goods_info;
				}
				return p_goods_info;
			}
			return nullptr;
		}
		void set_goods_info(mps_update_goods* in_goods_info)
		{
			if (nullptr == p_goods_info)
			{
				p_goods_info = in_goods_info;
				flag_goods_info = true;
			}
		}
	public:
		int32_t buy_date{};

	public:
		mrpc_account_storage_buy_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::account_storage_buy_cs, tag)
		{
		}
		mrpc_account_storage_buy_cs() : RpcPacket(mpe_rpc_cmd::account_storage_buy_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_goods_info);
			if (true == flag_goods_info)
			{
				if (nullptr != p_goods_info)
					protocol::SerializeType(pBuffer, p_goods_info);
				else
					protocol::SerializeType(pBuffer, &goods_info);
			}
			protocol::SerializeType(pBuffer, &buy_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_account_storage_buy_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_info = false;
		mps_account_storage info;
		mps_account_storage* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_account_storage* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_account_storage* get_info() const
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
		void set_info(mps_account_storage* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	private:
		bool flag_goods_info = false;
		mps_update_goods goods_info;
		mps_update_goods* p_goods_info = nullptr;
	public:
		bool has_goods_info() const
		{
			return flag_goods_info;
		}
		mps_update_goods* alloc_goods_info()
		{
			flag_goods_info = true;
			return &goods_info;
		}
		const mps_update_goods* get_goods_info() const
		{
			if (true == flag_goods_info)
			{
				if (nullptr == p_goods_info)
				{
					return &goods_info;
				}
				return p_goods_info;
			}
			return nullptr;
		}
		void set_goods_info(mps_update_goods* in_goods_info)
		{
			if (nullptr == p_goods_info)
			{
				p_goods_info = in_goods_info;
				flag_goods_info = true;
			}
		}
	private:
		bool flag_account_storage = false;
		mps_inventory account_storage;
		mps_inventory* p_account_storage = nullptr;
	public:
		bool has_account_storage() const
		{
			return flag_account_storage;
		}
		mps_inventory* alloc_account_storage()
		{
			flag_account_storage = true;
			return &account_storage;
		}
		const mps_inventory* get_account_storage() const
		{
			if (true == flag_account_storage)
			{
				if (nullptr == p_account_storage)
				{
					return &account_storage;
				}
				return p_account_storage;
			}
			return nullptr;
		}
		void set_account_storage(mps_inventory* in_account_storage)
		{
			if (nullptr == p_account_storage)
			{
				p_account_storage = in_account_storage;
				flag_account_storage = true;
			}
		}

	public:
		mrpc_account_storage_buy_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::account_storage_buy_sc, tag)
		{
		}
		mrpc_account_storage_buy_sc() : RpcPacket(mpe_rpc_cmd::account_storage_buy_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_goods_info);
			if (true == flag_goods_info)
			{
				if (nullptr != p_goods_info)
					protocol::SerializeType(pBuffer, p_goods_info);
				else
					protocol::SerializeType(pBuffer, &goods_info);
			}
			protocol::SerializeType(pBuffer, &flag_account_storage);
			if (true == flag_account_storage)
			{
				if (nullptr != p_account_storage)
					protocol::SerializeType(pBuffer, p_account_storage);
				else
					protocol::SerializeType(pBuffer, &account_storage);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
