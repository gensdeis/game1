#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_iuid.h"
#include "struct/mps_item.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mp_guild_storage_supply_insert_item_cs : public BasePacket 	// 문파 보급 창고에 아이템 넣기
	{
	public:
		std::vector<mps_item_iuid> list_item{};	// 넣는 아이템

	public:
		mp_guild_storage_supply_insert_item_cs() : BasePacket(mpe_cmd::guild_storage_supply_insert_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_item);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_storage_supply_insert_item_sc : public BasePacket 	// 문파 보급 창고에 아이템 넣기
	{
	private:
		bool flag_update_storage_item = false;
		mps_item update_storage_item;	// 창고에 추가된 아이템
		mps_item* p_update_storage_item = nullptr;
	public:
		bool has_update_storage_item() const
		{
			return flag_update_storage_item;
		}
		mps_item* alloc_update_storage_item()
		{
			flag_update_storage_item = true;
			return &update_storage_item;
		}
		const mps_item* get_update_storage_item() const
		{
			if (true == flag_update_storage_item)
			{
				if (nullptr == p_update_storage_item)
				{
					return &update_storage_item;
				}
				return p_update_storage_item;
			}
			return nullptr;
		}
		void set_update_storage_item(mps_item* in_update_storage_item)
		{
			if (nullptr == p_update_storage_item)
			{
				p_update_storage_item = in_update_storage_item;
				flag_update_storage_item = true;
			}
		}
	public:
		std::vector<mps_item_count_update> list_update_user_item{};	// 넣은 아이템

	public:
		mp_guild_storage_supply_insert_item_sc() : BasePacket(mpe_cmd::guild_storage_supply_insert_item_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_update_storage_item);
			if (true == flag_update_storage_item)
			{
				if (nullptr != p_update_storage_item)
					protocol::SerializeType(pBuffer, p_update_storage_item);
				else
					protocol::SerializeType(pBuffer, &update_storage_item);
			}
			protocol::SerializeType(pBuffer, &list_update_user_item);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
