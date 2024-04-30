#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_illusion_dungeon.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mp_illusion_dungeon_time_charge_cs : public BasePacket 
	{
	public:
		int32_t gid{};	// group_id
	public:
		int64_t iuid{};	// 아이템 uid

	public:
		mp_illusion_dungeon_time_charge_cs() : BasePacket(mpe_cmd::illusion_dungeon_time_charge_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &iuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_illusion_dungeon_time_charge_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_illusion_dungeon info;	// 던전 정보
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
		bool flag_item_info = false;
		mps_item_count_update item_info;	// 아이템 소모 정보
		mps_item_count_update* p_item_info = nullptr;
	public:
		bool has_item_info() const
		{
			return flag_item_info;
		}
		mps_item_count_update* alloc_item_info()
		{
			flag_item_info = true;
			return &item_info;
		}
		const mps_item_count_update* get_item_info() const
		{
			if (true == flag_item_info)
			{
				if (nullptr == p_item_info)
				{
					return &item_info;
				}
				return p_item_info;
			}
			return nullptr;
		}
		void set_item_info(mps_item_count_update* in_item_info)
		{
			if (nullptr == p_item_info)
			{
				p_item_info = in_item_info;
				flag_item_info = true;
			}
		}

	public:
		mp_illusion_dungeon_time_charge_sc() : BasePacket(mpe_cmd::illusion_dungeon_time_charge_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_item_info);
			if (true == flag_item_info)
			{
				if (nullptr != p_item_info)
					protocol::SerializeType(pBuffer, p_item_info);
				else
					protocol::SerializeType(pBuffer, &item_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
