#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_vehicle.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mp_vehicle_add_cs : public BasePacket 
	{
	public:
		int64_t iuid{};	// 사용 아이템

	public:
		mp_vehicle_add_cs() : BasePacket(mpe_cmd::vehicle_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &iuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_vehicle_add_sc : public BasePacket 
	{
	private:
		bool flag_info = false;
		mps_vehicle info;	// 탈것정보
		mps_vehicle* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_vehicle* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_vehicle* get_info() const
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
		void set_info(mps_vehicle* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	private:
		bool flag_update_item = false;
		mps_item_count_update update_item;	// 사용 정보 / 수정 -> mps_item_add
		mps_item_count_update* p_update_item = nullptr;
	public:
		bool has_update_item() const
		{
			return flag_update_item;
		}
		mps_item_count_update* alloc_update_item()
		{
			flag_update_item = true;
			return &update_item;
		}
		const mps_item_count_update* get_update_item() const
		{
			if (true == flag_update_item)
			{
				if (nullptr == p_update_item)
				{
					return &update_item;
				}
				return p_update_item;
			}
			return nullptr;
		}
		void set_update_item(mps_item_count_update* in_update_item)
		{
			if (nullptr == p_update_item)
			{
				p_update_item = in_update_item;
				flag_update_item = true;
			}
		}
	public:
		int32_t inven_weight{};	// 인벤무게

	public:
		mp_vehicle_add_sc() : BasePacket(mpe_cmd::vehicle_add_sc)
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
			protocol::SerializeType(pBuffer, &flag_update_item);
			if (true == flag_update_item)
			{
				if (nullptr != p_update_item)
					protocol::SerializeType(pBuffer, p_update_item);
				else
					protocol::SerializeType(pBuffer, &update_item);
			}
			protocol::SerializeType(pBuffer, &inven_weight);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
