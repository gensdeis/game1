#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_pickup.h"
#include "struct/mps_item_add.h"
#include "struct/mps_item_pickup.h"

namespace mir3d
{
	class mp_zone_item_pickup_cs : public BasePacket 
	{
	public:
		std::vector<mps_item_pickup> info{};	// 획득 아이템정보
	public:
		bool is_pet{};	// 팻 : true 캐릭터 : false

	public:
		mp_zone_item_pickup_cs() : BasePacket(mpe_cmd::zone_item_pickup_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &is_pet);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_zone_item_pickup_sc : public BasePacket 
	{
	public:
		bool is_pet{};	// 팻 : true 캐릭터 : false
	public:
		float weight{};	// 가방 무게
	private:
		bool flag_info = false;
		mps_item_add info;	// 아이템 정보
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
		std::vector<mps_item_pickup> pick_info{};	// 획득 아이템 정보

	public:
		mp_zone_item_pickup_sc() : BasePacket(mpe_cmd::zone_item_pickup_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &is_pet);
			protocol::SerializeType(pBuffer, &weight);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &pick_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
