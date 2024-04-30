#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_iuid.h"
#include "struct/mps_item_add.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mp_guild_storage_share_insert_item_cs : public BasePacket 	// 문파 공유 창고에 아이템 넣기
	{
	public:
		std::vector<mps_item_iuid> list_item{};	// 넣는 아이템

	public:
		mp_guild_storage_share_insert_item_cs() : BasePacket(mpe_cmd::guild_storage_share_insert_item_cs)
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

	class mp_guild_storage_share_insert_item_sc : public BasePacket 	// 문파 공유 창고에 아이템 넣기
	{
	public:
		mpe_error error{};
	private:
		bool flag_update_storage_item = false;
		mps_item_add update_storage_item;	// 창고에 추가된 아이템
		mps_item_add* p_update_storage_item = nullptr;
	public:
		bool has_update_storage_item() const
		{
			return flag_update_storage_item;
		}
		mps_item_add* alloc_update_storage_item()
		{
			flag_update_storage_item = true;
			return &update_storage_item;
		}
		const mps_item_add* get_update_storage_item() const
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
		void set_update_storage_item(mps_item_add* in_update_storage_item)
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
		int32_t available_time{};

	public:
		mp_guild_storage_share_insert_item_sc() : BasePacket(mpe_cmd::guild_storage_share_insert_item_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &error);
			protocol::SerializeType(pBuffer, &flag_update_storage_item);
			if (true == flag_update_storage_item)
			{
				if (nullptr != p_update_storage_item)
					protocol::SerializeType(pBuffer, p_update_storage_item);
				else
					protocol::SerializeType(pBuffer, &update_storage_item);
			}
			protocol::SerializeType(pBuffer, &list_update_user_item);
			protocol::SerializeType(pBuffer, &available_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
