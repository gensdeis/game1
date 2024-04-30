#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_decrement_item_durability.h"

namespace mir3d
{
	class mp_zone_character_drop_cs : public BasePacket 
	{

	public:
		mp_zone_character_drop_cs() : BasePacket(mpe_cmd::zone_character_drop_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_zone_character_drop_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_item_add info;	//  삭제 되어야 할 아이템 정보
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
	public:
		float weight{};	// 가방 무게
	public:
		int32_t killer_type{};	// 죽인 오브젝트 타입
	public:
		int64_t killer_id{};	// "죽인 오브젝트 uid (character : uid, etc : table id)"
	public:
		int32_t protect_equip{};	// 보호 슬롯 정보
	private:
		bool flag_item_durability = false;
		mps_decrement_item_durability item_durability;	// 사망시 내구도가 감소된 아이템
		mps_decrement_item_durability* p_item_durability = nullptr;
	public:
		bool has_item_durability() const
		{
			return flag_item_durability;
		}
		mps_decrement_item_durability* alloc_item_durability()
		{
			flag_item_durability = true;
			return &item_durability;
		}
		const mps_decrement_item_durability* get_item_durability() const
		{
			if (true == flag_item_durability)
			{
				if (nullptr == p_item_durability)
				{
					return &item_durability;
				}
				return p_item_durability;
			}
			return nullptr;
		}
		void set_item_durability(mps_decrement_item_durability* in_item_durability)
		{
			if (nullptr == p_item_durability)
			{
				p_item_durability = in_item_durability;
				flag_item_durability = true;
			}
		}
	public:
		std::string killer_name{};	// 죽인 오브젝트 이름

	public:
		mp_zone_character_drop_sc() : BasePacket(mpe_cmd::zone_character_drop_sc)
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
			protocol::SerializeType(pBuffer, &weight);
			protocol::SerializeType(pBuffer, &killer_type);
			protocol::SerializeType(pBuffer, &killer_id);
			protocol::SerializeType(pBuffer, &protect_equip);
			protocol::SerializeType(pBuffer, &flag_item_durability);
			if (true == flag_item_durability)
			{
				if (nullptr != p_item_durability)
					protocol::SerializeType(pBuffer, p_item_durability);
				else
					protocol::SerializeType(pBuffer, &item_durability);
			}
			protocol::SerializeType(pBuffer, &killer_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
