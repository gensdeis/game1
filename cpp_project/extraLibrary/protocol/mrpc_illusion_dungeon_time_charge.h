#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_illusion_dungeon.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mrpc_illusion_dungeon_time_charge_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	private:
		bool flag_info = false;
		mps_illusion_dungeon info;
		mps_illusion_dungeon* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_illusion_dungeon* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_illusion_dungeon* get_info() const
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
		void set_info(mps_illusion_dungeon* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	private:
		bool flag_update_item = false;
		mps_item_count_update update_item;
		mps_item_count_update* p_update_item = nullptr;
	public:
		bool has_update_item() const
		{
			return flag_update_item;
		}
		mps_item_count_update* alloc_update_item()
		{
			flag_update_item = true;
			return &update_item;
		}
		const mps_item_count_update* get_update_item() const
		{
			if (true == flag_update_item)
			{
				if (nullptr == p_update_item)
				{
					return &update_item;
				}
				return p_update_item;
			}
			return nullptr;
		}
		void set_update_item(mps_item_count_update* in_update_item)
		{
			if (nullptr == p_update_item)
			{
				p_update_item = in_update_item;
				flag_update_item = true;
			}
		}

	public:
		mrpc_illusion_dungeon_time_charge_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::illusion_dungeon_time_charge_cs, tag)
		{
		}
		mrpc_illusion_dungeon_time_charge_cs() : RpcPacket(mpe_rpc_cmd::illusion_dungeon_time_charge_cs)
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
			protocol::SerializeType(pBuffer, &flag_update_item);
			if (true == flag_update_item)
			{
				if (nullptr != p_update_item)
					protocol::SerializeType(pBuffer, p_update_item);
				else
					protocol::SerializeType(pBuffer, &update_item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_illusion_dungeon_time_charge_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_illusion_dungeon_time_charge_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::illusion_dungeon_time_charge_sc, tag)
		{
		}
		mrpc_illusion_dungeon_time_charge_sc() : RpcPacket(mpe_rpc_cmd::illusion_dungeon_time_charge_sc)
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
