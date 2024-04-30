#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mrpc_guild_storage_supply_insert_item_cs : public RpcPacket 	// 문파 보급 창고에 아이템 넣기
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		int32_t item_id{};
	private:
		bool flag_item = false;
		mps_item_add item;	// 넣는 아이템
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
		mrpc_guild_storage_supply_insert_item_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_supply_insert_item_cs, tag)
		{
		}
		mrpc_guild_storage_supply_insert_item_cs() : RpcPacket(mpe_rpc_cmd::guild_storage_supply_insert_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &item_id);
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

	class mrpc_guild_storage_supply_insert_item_sc : public RpcPacket 	// 문파 보급 창고에 아이템 넣기
	{

	public:
		mrpc_guild_storage_supply_insert_item_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_storage_supply_insert_item_sc, tag)
		{
		}
		mrpc_guild_storage_supply_insert_item_sc() : RpcPacket(mpe_rpc_cmd::guild_storage_supply_insert_item_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
