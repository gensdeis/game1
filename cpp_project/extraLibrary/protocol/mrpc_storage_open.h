#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_inventory.h"
#include "struct/mps_inventory.h"
#include "struct/mps_account_storage.h"

namespace mir3d
{
	class mrpc_storage_open_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		bool is_account_storage{};	// 계정 창고 보유 유무
	public:
		bool user_open{};	// 유저요청

	public:
		mrpc_storage_open_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::storage_open_cs, tag)
		{
		}
		mrpc_storage_open_cs() : RpcPacket(mpe_rpc_cmd::storage_open_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &is_account_storage);
			protocol::SerializeType(pBuffer, &user_open);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_storage_open_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_private_storage = false;
		mps_inventory private_storage;	// 개인창고 아이템
		mps_inventory* p_private_storage = nullptr;
	public:
		bool has_private_storage() const
		{
			return flag_private_storage;
		}
		mps_inventory* alloc_private_storage()
		{
			flag_private_storage = true;
			return &private_storage;
		}
		const mps_inventory* get_private_storage() const
		{
			if (true == flag_private_storage)
			{
				if (nullptr == p_private_storage)
				{
					return &private_storage;
				}
				return p_private_storage;
			}
			return nullptr;
		}
		void set_private_storage(mps_inventory* in_private_storage)
		{
			if (nullptr == p_private_storage)
			{
				p_private_storage = in_private_storage;
				flag_private_storage = true;
			}
		}
	private:
		bool flag_account_storage = false;
		mps_inventory account_storage;	// 계정창고 아이템
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
	private:
		bool flag_info = false;
		mps_account_storage info;	// 계정창고 정보
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
	public:
		bool user_open{};	// 유저요청

	public:
		mrpc_storage_open_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::storage_open_sc, tag)
		{
		}
		mrpc_storage_open_sc() : RpcPacket(mpe_rpc_cmd::storage_open_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_private_storage);
			if (true == flag_private_storage)
			{
				if (nullptr != p_private_storage)
					protocol::SerializeType(pBuffer, p_private_storage);
				else
					protocol::SerializeType(pBuffer, &private_storage);
			}
			protocol::SerializeType(pBuffer, &flag_account_storage);
			if (true == flag_account_storage)
			{
				if (nullptr != p_account_storage)
					protocol::SerializeType(pBuffer, p_account_storage);
				else
					protocol::SerializeType(pBuffer, &account_storage);
			}
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &user_open);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
