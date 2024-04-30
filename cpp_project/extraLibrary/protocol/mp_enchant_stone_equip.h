#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_enchant_stone_update.h"

namespace mir3d
{
	class mp_enchant_stone_equip_cs : public BasePacket 
	{
	public:
		int64_t iuid{};	// 대상 아이템 uid
	public:
		mpe_item_reinforce_position pos{};	// 대상 아이템의 위치
	public:
		int64_t stone_uid{};	// 용령석 iuid
	public:
		int32_t index{};	// 슬롯위치
	public:
		bool equip_flag{};	// "true : 착용, false : 해제"

	public:
		mp_enchant_stone_equip_cs() : BasePacket(mpe_cmd::enchant_stone_equip_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &stone_uid);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &equip_flag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_enchant_stone_equip_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_item_add info;	// 변경된 아이템 정보 / 수정 -> mps_item_add
		mps_item_add* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_item_add* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_item_add* get_info() const
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
		void set_info(mps_item_add* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	private:
		bool flag_update_info = false;
		mps_enchant_stone_update update_info;	// 변경된 용령석 슬롯 정보
		mps_enchant_stone_update* p_update_info = nullptr;
	public:
		bool has_update_info() const
		{
			return flag_update_info;
		}
		mps_enchant_stone_update* alloc_update_info()
		{
			flag_update_info = true;
			return &update_info;
		}
		const mps_enchant_stone_update* get_update_info() const
		{
			if (true == flag_update_info)
			{
				if (nullptr == p_update_info)
				{
					return &update_info;
				}
				return p_update_info;
			}
			return nullptr;
		}
		void set_update_info(mps_enchant_stone_update* in_update_info)
		{
			if (nullptr == p_update_info)
			{
				p_update_info = in_update_info;
				flag_update_info = true;
			}
		}

	public:
		mp_enchant_stone_equip_sc() : BasePacket(mpe_cmd::enchant_stone_equip_sc)
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
			protocol::SerializeType(pBuffer, &flag_update_info);
			if (true == flag_update_info)
			{
				if (nullptr != p_update_info)
					protocol::SerializeType(pBuffer, p_update_info);
				else
					protocol::SerializeType(pBuffer, &update_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
