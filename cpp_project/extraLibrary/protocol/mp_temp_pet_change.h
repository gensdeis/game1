#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_add.h"
#include "struct/mps_temp_pet.h"

namespace mir3d
{
	class mp_temp_pet_change_cs : public BasePacket 
	{
	public:
		int64_t uid{};	// 보관함 uid

	public:
		mp_temp_pet_change_cs() : BasePacket(mpe_cmd::temp_pet_change_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_temp_pet_change_sc : public BasePacket 
	{
	private:
		bool flag_item_add = false;
		mps_item_add item_add;
		mps_item_add* p_item_add = nullptr;
	public:
		bool has_item_add() const
		{
			return flag_item_add;
		}
		mps_item_add* alloc_item_add()
		{
			flag_item_add = true;
			return &item_add;
		}
		const mps_item_add* get_item_add() const
		{
			if (true == flag_item_add)
			{
				if (nullptr == p_item_add)
				{
					return &item_add;
				}
				return p_item_add;
			}
			return nullptr;
		}
		void set_item_add(mps_item_add* in_item_add)
		{
			if (nullptr == p_item_add)
			{
				p_item_add = in_item_add;
				flag_item_add = true;
			}
		}
	private:
		bool flag_temp_pet = false;
		mps_temp_pet temp_pet;	// 변경된 정보
		mps_temp_pet* p_temp_pet = nullptr;
	public:
		bool has_temp_pet() const
		{
			return flag_temp_pet;
		}
		mps_temp_pet* alloc_temp_pet()
		{
			flag_temp_pet = true;
			return &temp_pet;
		}
		const mps_temp_pet* get_temp_pet() const
		{
			if (true == flag_temp_pet)
			{
				if (nullptr == p_temp_pet)
				{
					return &temp_pet;
				}
				return p_temp_pet;
			}
			return nullptr;
		}
		void set_temp_pet(mps_temp_pet* in_temp_pet)
		{
			if (nullptr == p_temp_pet)
			{
				p_temp_pet = in_temp_pet;
				flag_temp_pet = true;
			}
		}

	public:
		mp_temp_pet_change_sc() : BasePacket(mpe_cmd::temp_pet_change_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_item_add);
			if (true == flag_item_add)
			{
				if (nullptr != p_item_add)
					protocol::SerializeType(pBuffer, p_item_add);
				else
					protocol::SerializeType(pBuffer, &item_add);
			}
			protocol::SerializeType(pBuffer, &flag_temp_pet);
			if (true == flag_temp_pet)
			{
				if (nullptr != p_temp_pet)
					protocol::SerializeType(pBuffer, p_temp_pet);
				else
					protocol::SerializeType(pBuffer, &temp_pet);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
