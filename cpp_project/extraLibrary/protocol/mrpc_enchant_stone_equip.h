#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_enchant_stone_update.h"
#include "struct/mrpcs_enchant_stone_db_item.h"

namespace mir3d
{
	class mrpc_enchant_stone_equip_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_info = false;
		mrpcs_enchant_stone_update info;	// 아이템에 착용된 용령석 정보 
		mrpcs_enchant_stone_update* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_enchant_stone_update* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_enchant_stone_update* get_info() const
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
		void set_info(mrpcs_enchant_stone_update* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	private:
		bool flag_db_item_update = false;
		mrpcs_enchant_stone_db_item db_item_update;
		mrpcs_enchant_stone_db_item* p_db_item_update = nullptr;
	public:
		bool has_db_item_update() const
		{
			return flag_db_item_update;
		}
		mrpcs_enchant_stone_db_item* alloc_db_item_update()
		{
			flag_db_item_update = true;
			return &db_item_update;
		}
		const mrpcs_enchant_stone_db_item* get_db_item_update() const
		{
			if (true == flag_db_item_update)
			{
				if (nullptr == p_db_item_update)
				{
					return &db_item_update;
				}
				return p_db_item_update;
			}
			return nullptr;
		}
		void set_db_item_update(mrpcs_enchant_stone_db_item* in_db_item_update)
		{
			if (nullptr == p_db_item_update)
			{
				p_db_item_update = in_db_item_update;
				flag_db_item_update = true;
			}
		}

	public:
		mrpc_enchant_stone_equip_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::enchant_stone_equip_cs, tag)
		{
		}
		mrpc_enchant_stone_equip_cs() : RpcPacket(mpe_rpc_cmd::enchant_stone_equip_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_db_item_update);
			if (true == flag_db_item_update)
			{
				if (nullptr != p_db_item_update)
					protocol::SerializeType(pBuffer, p_db_item_update);
				else
					protocol::SerializeType(pBuffer, &db_item_update);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_enchant_stone_equip_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_enchant_stone_equip_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::enchant_stone_equip_sc, tag)
		{
		}
		mrpc_enchant_stone_equip_sc() : RpcPacket(mpe_rpc_cmd::enchant_stone_equip_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
