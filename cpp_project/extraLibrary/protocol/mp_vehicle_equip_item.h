#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_list_vehicle_equip_item.h"

namespace mir3d
{
	class mp_vehicle_equip_item_cs : public BasePacket 
	{
	public:
		int32_t vehicle_tid{};	// 탈것
	public:
		int64_t iuid{};	// 장비아이템
	public:
		mpe_equip_flag flag{};	// 장착/해제

	public:
		mp_vehicle_equip_item_cs() : BasePacket(mpe_cmd::vehicle_equip_item_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &vehicle_tid);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeEnum(pBuffer, &flag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_vehicle_equip_item_sc : public BasePacket 
	{
	public:
		int32_t vehicle_tid{};
	private:
		bool flag_info = false;
		mps_list_vehicle_equip_item info;	// 변경 정보
		mps_list_vehicle_equip_item* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_list_vehicle_equip_item* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_list_vehicle_equip_item* get_info() const
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
		void set_info(mps_list_vehicle_equip_item* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mp_vehicle_equip_item_sc() : BasePacket(mpe_cmd::vehicle_equip_item_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &vehicle_tid);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
