#pragma once
#include <vector>
#include <string>
#include "mps_enchant_stone.h"
#include "mps_enchant_stone.h"
#include "mps_enchant_stone.h"

namespace mir3d
{
	class mps_expert_equipment_info 	// 신기 장비 정보
	{
	public:
		int32_t table_id{};	// "엑셀 테이블의 id"
	public:
		uint8_t reinforce_level{};	// "장비 강화 레벨"
	public:
		uint8_t is_equiped{};	// "착용 완료 여부 0:미착용, 1:착용중"
	public:
		int64_t enchant_stone_slot1{};	// "용령석착용 슬롯1 슬롯막힘:-1,슬롯개방:0,아이템착용:iuid"
	public:
		int64_t enchant_stone_slot2{};	// "용령석착용 슬롯2 슬롯막힘:-1,슬롯개방:0,아이템착용:iuid"
	public:
		int64_t enchant_stone_slot3{};	// "용령석착용 슬롯3 슬롯막힘:-1,슬롯개방:0,아이템착용:iuid"
	private:
		bool flag_slot1_enchant_stone_info = false;
		mps_enchant_stone slot1_enchant_stone_info;	// "슬롯1 의 용령석 정보 (착용된 경우 유효)"
		mps_enchant_stone* p_slot1_enchant_stone_info = nullptr;
	public:
		bool has_slot1_enchant_stone_info() const
		{
			return flag_slot1_enchant_stone_info;
		}
		mps_enchant_stone* alloc_slot1_enchant_stone_info()
		{
			flag_slot1_enchant_stone_info = true;
			return &slot1_enchant_stone_info;
		}
		const mps_enchant_stone* get_slot1_enchant_stone_info() const
		{
			if (true == flag_slot1_enchant_stone_info)
			{
				if (nullptr == p_slot1_enchant_stone_info)
				{
					return &slot1_enchant_stone_info;
				}
				return p_slot1_enchant_stone_info;
			}
			return nullptr;
		}
		void set_slot1_enchant_stone_info(mps_enchant_stone* in_slot1_enchant_stone_info)
		{
			if (nullptr == p_slot1_enchant_stone_info)
			{
				p_slot1_enchant_stone_info = in_slot1_enchant_stone_info;
				flag_slot1_enchant_stone_info = true;
			}
		}
	private:
		bool flag_slot2_enchant_stone_info = false;
		mps_enchant_stone slot2_enchant_stone_info;	// "슬롯2 의 용령석 정보 (착용된 경우 유효)"
		mps_enchant_stone* p_slot2_enchant_stone_info = nullptr;
	public:
		bool has_slot2_enchant_stone_info() const
		{
			return flag_slot2_enchant_stone_info;
		}
		mps_enchant_stone* alloc_slot2_enchant_stone_info()
		{
			flag_slot2_enchant_stone_info = true;
			return &slot2_enchant_stone_info;
		}
		const mps_enchant_stone* get_slot2_enchant_stone_info() const
		{
			if (true == flag_slot2_enchant_stone_info)
			{
				if (nullptr == p_slot2_enchant_stone_info)
				{
					return &slot2_enchant_stone_info;
				}
				return p_slot2_enchant_stone_info;
			}
			return nullptr;
		}
		void set_slot2_enchant_stone_info(mps_enchant_stone* in_slot2_enchant_stone_info)
		{
			if (nullptr == p_slot2_enchant_stone_info)
			{
				p_slot2_enchant_stone_info = in_slot2_enchant_stone_info;
				flag_slot2_enchant_stone_info = true;
			}
		}
	private:
		bool flag_slot3_enchant_stone_info = false;
		mps_enchant_stone slot3_enchant_stone_info;	// "슬롯3 의 용령석 정보 (착용된 경우 유효)"
		mps_enchant_stone* p_slot3_enchant_stone_info = nullptr;
	public:
		bool has_slot3_enchant_stone_info() const
		{
			return flag_slot3_enchant_stone_info;
		}
		mps_enchant_stone* alloc_slot3_enchant_stone_info()
		{
			flag_slot3_enchant_stone_info = true;
			return &slot3_enchant_stone_info;
		}
		const mps_enchant_stone* get_slot3_enchant_stone_info() const
		{
			if (true == flag_slot3_enchant_stone_info)
			{
				if (nullptr == p_slot3_enchant_stone_info)
				{
					return &slot3_enchant_stone_info;
				}
				return p_slot3_enchant_stone_info;
			}
			return nullptr;
		}
		void set_slot3_enchant_stone_info(mps_enchant_stone* in_slot3_enchant_stone_info)
		{
			if (nullptr == p_slot3_enchant_stone_info)
			{
				p_slot3_enchant_stone_info = in_slot3_enchant_stone_info;
				flag_slot3_enchant_stone_info = true;
			}
		}

	public:
		mps_expert_equipment_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &reinforce_level);
			protocol::SerializeType(pBuffer, &is_equiped);
			protocol::SerializeType(pBuffer, &enchant_stone_slot1);
			protocol::SerializeType(pBuffer, &enchant_stone_slot2);
			protocol::SerializeType(pBuffer, &enchant_stone_slot3);
			protocol::SerializeType(pBuffer, &flag_slot1_enchant_stone_info);
			if (true == flag_slot1_enchant_stone_info)
			{
				if (nullptr != p_slot1_enchant_stone_info)
					protocol::SerializeType(pBuffer, p_slot1_enchant_stone_info);
				else
					protocol::SerializeType(pBuffer, &slot1_enchant_stone_info);
			}
			protocol::SerializeType(pBuffer, &flag_slot2_enchant_stone_info);
			if (true == flag_slot2_enchant_stone_info)
			{
				if (nullptr != p_slot2_enchant_stone_info)
					protocol::SerializeType(pBuffer, p_slot2_enchant_stone_info);
				else
					protocol::SerializeType(pBuffer, &slot2_enchant_stone_info);
			}
			protocol::SerializeType(pBuffer, &flag_slot3_enchant_stone_info);
			if (true == flag_slot3_enchant_stone_info)
			{
				if (nullptr != p_slot3_enchant_stone_info)
					protocol::SerializeType(pBuffer, p_slot3_enchant_stone_info);
				else
					protocol::SerializeType(pBuffer, &slot3_enchant_stone_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
