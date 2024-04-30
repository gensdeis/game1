#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_guild_storage_supply_get_item_cs : public BasePacket 	// 문파 보급 창고서 아이템 빼기
	{
	public:
		int32_t item_tid{};
	public:
		int32_t request_count{};

	public:
		mp_guild_storage_supply_get_item_cs() : BasePacket(mpe_cmd::guild_storage_supply_get_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &item_tid);
			protocol::SerializeType(pBuffer, &request_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_storage_supply_get_item_sc : public BasePacket 	// 문파 보급 창고서 아이템 빼기
	{
	private:
		bool flag_update_storage_item = false;
		mps_item update_storage_item;	// 창고에서 빠진 아이템
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
	private:
		bool flag_update_user_item = false;
		mps_item_add update_user_item;	// 인벤에 추가된 아이템
		mps_item_add* p_update_user_item = nullptr;
	public:
		bool has_update_user_item() const
		{
			return flag_update_user_item;
		}
		mps_item_add* alloc_update_user_item()
		{
			flag_update_user_item = true;
			return &update_user_item;
		}
		const mps_item_add* get_update_user_item() const
		{
			if (true == flag_update_user_item)
			{
				if (nullptr == p_update_user_item)
				{
					return &update_user_item;
				}
				return p_update_user_item;
			}
			return nullptr;
		}
		void set_update_user_item(mps_item_add* in_update_user_item)
		{
			if (nullptr == p_update_user_item)
			{
				p_update_user_item = in_update_user_item;
				flag_update_user_item = true;
			}
		}
	public:
		int32_t current_get_item_count{};	// 현재 찾기 횟수

	public:
		mp_guild_storage_supply_get_item_sc() : BasePacket(mpe_cmd::guild_storage_supply_get_item_sc)
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
			protocol::SerializeType(pBuffer, &flag_update_user_item);
			if (true == flag_update_user_item)
			{
				if (nullptr != p_update_user_item)
					protocol::SerializeType(pBuffer, p_update_user_item);
				else
					protocol::SerializeType(pBuffer, &update_user_item);
			}
			protocol::SerializeType(pBuffer, &current_get_item_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
