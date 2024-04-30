#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mrpcs_item_stone_pair.h"
#include "struct/mps_item_add.h"
#include "struct/mrpcs_item_stone_pair.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mrpc_guild_storage_share_insert_item_cs : public RpcPacket 	// 문파 공유 창고에 아이템 넣기
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
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
		std::vector<mrpcs_item_stone_pair> list_enchant_stone{};	// 같이 포함되는 용령석

	public:
		mrpc_guild_storage_share_insert_item_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_share_insert_item_cs, tag)
		{
		}
		mrpc_guild_storage_share_insert_item_cs() : RpcPacket(mpe_rpc_cmd::guild_storage_share_insert_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &flag_item);
			if (true == flag_item)
			{
				if (nullptr != p_item)
					protocol::SerializeType(pBuffer, p_item);
				else
					protocol::SerializeType(pBuffer, &item);
			}
			protocol::SerializeType(pBuffer, &list_enchant_stone);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_storage_share_insert_item_sc : public RpcPacket 	// 문파 공유 창고에 아이템 넣기
	{
	public:
		int64_t cuid{};
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
		std::vector<mrpcs_item_stone_pair> list_enchant_stone{};	// 같이 포함되는 용령석
	public:
		std::vector<mps_item_count_update> list_update_user_item{};	// 넣은 아이템
	public:
		int32_t available_time{};

	public:
		mrpc_guild_storage_share_insert_item_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_share_insert_item_sc, tag)
		{
		}
		mrpc_guild_storage_share_insert_item_sc() : RpcPacket(mpe_rpc_cmd::guild_storage_share_insert_item_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_update_storage_item);
			if (true == flag_update_storage_item)
			{
				if (nullptr != p_update_storage_item)
					protocol::SerializeType(pBuffer, p_update_storage_item);
				else
					protocol::SerializeType(pBuffer, &update_storage_item);
			}
			protocol::SerializeType(pBuffer, &list_enchant_stone);
			protocol::SerializeType(pBuffer, &list_update_user_item);
			protocol::SerializeType(pBuffer, &available_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
