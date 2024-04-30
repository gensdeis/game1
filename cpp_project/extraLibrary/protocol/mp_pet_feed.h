#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_pet_info.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_pet_feed_cs : public BasePacket 	// 펫 먹이 사용
	{
	public:
		int32_t pet_id{};	// 펫아이디
	public:
		int32_t food_id{};	// 먹이 아이템 아이디
	public:
		mpe_vehicle_food_use use_type{};	// 사용 타입
	public:
		std::vector<int32_t> list_tid{};

	public:
		mp_pet_feed_cs() : BasePacket(mpe_cmd::pet_feed_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &pet_id);
			protocol::SerializeType(pBuffer, &food_id);
			protocol::SerializeEnum(pBuffer, &use_type);
			protocol::SerializeType(pBuffer, &list_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_pet_feed_sc : public BasePacket 	// 펫 먹이 사용
	{
	private:
		bool flag_pet_info = false;
		mps_pet_info pet_info;
		mps_pet_info* p_pet_info = nullptr;
	public:
		bool has_pet_info() const
		{
			return flag_pet_info;
		}
		mps_pet_info* alloc_pet_info()
		{
			flag_pet_info = true;
			return &pet_info;
		}
		const mps_pet_info* get_pet_info() const
		{
			if (true == flag_pet_info)
			{
				if (nullptr == p_pet_info)
				{
					return &pet_info;
				}
				return p_pet_info;
			}
			return nullptr;
		}
		void set_pet_info(mps_pet_info* in_pet_info)
		{
			if (nullptr == p_pet_info)
			{
				p_pet_info = in_pet_info;
				flag_pet_info = true;
			}
		}
	private:
		bool flag_item_info = false;
		mps_item_add item_info;
		mps_item_add* p_item_info = nullptr;
	public:
		bool has_item_info() const
		{
			return flag_item_info;
		}
		mps_item_add* alloc_item_info()
		{
			flag_item_info = true;
			return &item_info;
		}
		const mps_item_add* get_item_info() const
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
		void set_item_info(mps_item_add* in_item_info)
		{
			if (nullptr == p_item_info)
			{
				p_item_info = in_item_info;
				flag_item_info = true;
			}
		}

	public:
		mp_pet_feed_sc() : BasePacket(mpe_cmd::pet_feed_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_pet_info);
			if (true == flag_pet_info)
			{
				if (nullptr != p_pet_info)
					protocol::SerializeType(pBuffer, p_pet_info);
				else
					protocol::SerializeType(pBuffer, &pet_info);
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
