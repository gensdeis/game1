#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods.h"
#include "struct/mps_inventory.h"
#include "struct/mps_account_storage.h"

namespace mir3d
{
	class mp_account_storage_buy_cs : public BasePacket 
	{
	public:
		int64_t npc_uid{};	// 창고 npc uid

	public:
		mp_account_storage_buy_cs() : BasePacket(mpe_cmd::account_storage_buy_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &npc_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_account_storage_buy_sc : public BasePacket 
	{
	private:
		bool flag_goods_info = false;
		mps_update_goods goods_info;	// 사용된 재화
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
		bool flag_account_storage_item = false;
		mps_inventory account_storage_item;	// 계정창고 아이템 정보
		mps_inventory* p_account_storage_item = nullptr;
	public:
		bool has_account_storage_item() const
		{
			return flag_account_storage_item;
		}
		mps_inventory* alloc_account_storage_item()
		{
			flag_account_storage_item = true;
			return &account_storage_item;
		}
		const mps_inventory* get_account_storage_item() const
		{
			if (true == flag_account_storage_item)
			{
				if (nullptr == p_account_storage_item)
				{
					return &account_storage_item;
				}
				return p_account_storage_item;
			}
			return nullptr;
		}
		void set_account_storage_item(mps_inventory* in_account_storage_item)
		{
			if (nullptr == p_account_storage_item)
			{
				p_account_storage_item = in_account_storage_item;
				flag_account_storage_item = true;
			}
		}
	private:
		bool flag_account_storage_info = false;
		mps_account_storage account_storage_info;	// 계정창고 정보
		mps_account_storage* p_account_storage_info = nullptr;
	public:
		bool has_account_storage_info() const
		{
			return flag_account_storage_info;
		}
		mps_account_storage* alloc_account_storage_info()
		{
			flag_account_storage_info = true;
			return &account_storage_info;
		}
		const mps_account_storage* get_account_storage_info() const
		{
			if (true == flag_account_storage_info)
			{
				if (nullptr == p_account_storage_info)
				{
					return &account_storage_info;
				}
				return p_account_storage_info;
			}
			return nullptr;
		}
		void set_account_storage_info(mps_account_storage* in_account_storage_info)
		{
			if (nullptr == p_account_storage_info)
			{
				p_account_storage_info = in_account_storage_info;
				flag_account_storage_info = true;
			}
		}

	public:
		mp_account_storage_buy_sc() : BasePacket(mpe_cmd::account_storage_buy_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_goods_info);
			if (true == flag_goods_info)
			{
				if (nullptr != p_goods_info)
					protocol::SerializeType(pBuffer, p_goods_info);
				else
					protocol::SerializeType(pBuffer, &goods_info);
			}
			protocol::SerializeType(pBuffer, &flag_account_storage_item);
			if (true == flag_account_storage_item)
			{
				if (nullptr != p_account_storage_item)
					protocol::SerializeType(pBuffer, p_account_storage_item);
				else
					protocol::SerializeType(pBuffer, &account_storage_item);
			}
			protocol::SerializeType(pBuffer, &flag_account_storage_info);
			if (true == flag_account_storage_info)
			{
				if (nullptr != p_account_storage_info)
					protocol::SerializeType(pBuffer, p_account_storage_info);
				else
					protocol::SerializeType(pBuffer, &account_storage_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
