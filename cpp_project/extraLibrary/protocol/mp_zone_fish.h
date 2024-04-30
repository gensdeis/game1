﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_gameitem_update.h"
#include "struct/mps_profesion.h"
#include "struct/mps_decrement_item_durability.h"

namespace mir3d
{
	class mp_zone_fish_cs : public BasePacket 
	{
	public:
		int64_t iuid{};
	public:
		mpe_object_collect_flag flag{};
	public:
		mpe_direction direction{};

	public:
		mp_zone_fish_cs() : BasePacket(mpe_cmd::zone_fish_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &flag);
			protocol::SerializeEnum(pBuffer, &direction);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_zone_fish_sc : public BasePacket 
	{
	public:
		mpe_object_collect_flag flag{};
	public:
		mpe_result_fish result{};	// 낚시 결과
	private:
		bool flag_info = false;
		mps_gameitem_update info;	// 결과 아이템
		mps_gameitem_update* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_gameitem_update* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_gameitem_update* get_info() const
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
		void set_info(mps_gameitem_update* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	private:
		bool flag_profesion = false;
		mps_profesion profesion;	// 대가 갱신
		mps_profesion* p_profesion = nullptr;
	public:
		bool has_profesion() const
		{
			return flag_profesion;
		}
		mps_profesion* alloc_profesion()
		{
			flag_profesion = true;
			return &profesion;
		}
		const mps_profesion* get_profesion() const
		{
			if (true == flag_profesion)
			{
				if (nullptr == p_profesion)
				{
					return &profesion;
				}
				return p_profesion;
			}
			return nullptr;
		}
		void set_profesion(mps_profesion* in_profesion)
		{
			if (nullptr == p_profesion)
			{
				p_profesion = in_profesion;
				flag_profesion = true;
			}
		}
	public:
		mpe_error error_code{};
	private:
		bool flag_durability_info = false;
		mps_decrement_item_durability durability_info;	// 아이템 내구도 변경 정보
		mps_decrement_item_durability* p_durability_info = nullptr;
	public:
		bool has_durability_info() const
		{
			return flag_durability_info;
		}
		mps_decrement_item_durability* alloc_durability_info()
		{
			flag_durability_info = true;
			return &durability_info;
		}
		const mps_decrement_item_durability* get_durability_info() const
		{
			if (true == flag_durability_info)
			{
				if (nullptr == p_durability_info)
				{
					return &durability_info;
				}
				return p_durability_info;
			}
			return nullptr;
		}
		void set_durability_info(mps_decrement_item_durability* in_durability_info)
		{
			if (nullptr == p_durability_info)
			{
				p_durability_info = in_durability_info;
				flag_durability_info = true;
			}
		}
	public:
		mpe_castle_town_specialties_pos specialties_pos{};	// 특산품 타입
	public:
		int32_t gather_value{};	// 특산품 수량

	public:
		mp_zone_fish_sc() : BasePacket(mpe_cmd::zone_fish_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &flag);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &flag_profesion);
			if (true == flag_profesion)
			{
				if (nullptr != p_profesion)
					protocol::SerializeType(pBuffer, p_profesion);
				else
					protocol::SerializeType(pBuffer, &profesion);
			}
			protocol::SerializeEnum(pBuffer, &error_code);
			protocol::SerializeType(pBuffer, &flag_durability_info);
			if (true == flag_durability_info)
			{
				if (nullptr != p_durability_info)
					protocol::SerializeType(pBuffer, p_durability_info);
				else
					protocol::SerializeType(pBuffer, &durability_info);
			}
			protocol::SerializeEnum(pBuffer, &specialties_pos);
			protocol::SerializeType(pBuffer, &gather_value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
