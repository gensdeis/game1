#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_pet_info.h"
#include "struct/mps_pet_info.h"

namespace mir3d
{
	class mp_pet_equip_cs : public BasePacket 
	{
	public:
		int32_t tid{};	// 장착펫아이디
	public:
		mpe_pet_pos pos{};	// 장착위치 - max이면 해제

	public:
		mp_pet_equip_cs() : BasePacket(mpe_cmd::pet_equip_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeEnum(pBuffer, &pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_pet_equip_sc : public BasePacket 
	{
	private:
		bool flag_equip_pet = false;
		mps_pet_info equip_pet;	// 장착펫
		mps_pet_info* p_equip_pet = nullptr;
	public:
		bool has_equip_pet() const
		{
			return flag_equip_pet;
		}
		mps_pet_info* alloc_equip_pet()
		{
			flag_equip_pet = true;
			return &equip_pet;
		}
		const mps_pet_info* get_equip_pet() const
		{
			if (true == flag_equip_pet)
			{
				if (nullptr == p_equip_pet)
				{
					return &equip_pet;
				}
				return p_equip_pet;
			}
			return nullptr;
		}
		void set_equip_pet(mps_pet_info* in_equip_pet)
		{
			if (nullptr == p_equip_pet)
			{
				p_equip_pet = in_equip_pet;
				flag_equip_pet = true;
			}
		}
	private:
		bool flag_release_pet = false;
		mps_pet_info release_pet;	// 해제펫
		mps_pet_info* p_release_pet = nullptr;
	public:
		bool has_release_pet() const
		{
			return flag_release_pet;
		}
		mps_pet_info* alloc_release_pet()
		{
			flag_release_pet = true;
			return &release_pet;
		}
		const mps_pet_info* get_release_pet() const
		{
			if (true == flag_release_pet)
			{
				if (nullptr == p_release_pet)
				{
					return &release_pet;
				}
				return p_release_pet;
			}
			return nullptr;
		}
		void set_release_pet(mps_pet_info* in_release_pet)
		{
			if (nullptr == p_release_pet)
			{
				p_release_pet = in_release_pet;
				flag_release_pet = true;
			}
		}
	public:
		std::vector<int32_t> list_special_move_slot{};	// 필살기 슬롯 배치

	public:
		mp_pet_equip_sc() : BasePacket(mpe_cmd::pet_equip_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_equip_pet);
			if (true == flag_equip_pet)
			{
				if (nullptr != p_equip_pet)
					protocol::SerializeType(pBuffer, p_equip_pet);
				else
					protocol::SerializeType(pBuffer, &equip_pet);
			}
			protocol::SerializeType(pBuffer, &flag_release_pet);
			if (true == flag_release_pet)
			{
				if (nullptr != p_release_pet)
					protocol::SerializeType(pBuffer, p_release_pet);
				else
					protocol::SerializeType(pBuffer, &release_pet);
			}
			protocol::SerializeType(pBuffer, &list_special_move_slot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
