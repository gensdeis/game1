#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item.h"

namespace mir3d
{
	class mrpc_guild_storage_material_add_cheat_cs : public RpcPacket 	// 문파 재료 창고에 넣기 (치트)
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t item_donation_tid{};
	public:
		int32_t item_donation_count{};

	public:
		mrpc_guild_storage_material_add_cheat_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_material_add_cheat_cs, tag)
		{
		}
		mrpc_guild_storage_material_add_cheat_cs() : RpcPacket(mpe_rpc_cmd::guild_storage_material_add_cheat_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &item_donation_tid);
			protocol::SerializeType(pBuffer, &item_donation_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_storage_material_add_cheat_sc : public RpcPacket 	// 문파 재료 창고에 넣기 (치트)
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
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
		int32_t item_donation_count{};

	public:
		mrpc_guild_storage_material_add_cheat_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_material_add_cheat_sc, tag)
		{
		}
		mrpc_guild_storage_material_add_cheat_sc() : RpcPacket(mpe_rpc_cmd::guild_storage_material_add_cheat_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_update_storage_item);
			if (true == flag_update_storage_item)
			{
				if (nullptr != p_update_storage_item)
					protocol::SerializeType(pBuffer, p_update_storage_item);
				else
					protocol::SerializeType(pBuffer, &update_storage_item);
			}
			protocol::SerializeType(pBuffer, &item_donation_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
