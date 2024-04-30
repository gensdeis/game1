#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_teleport_area.h"
#include "struct/mps_item_add.h"

namespace mir3d
{
	class mp_zone_teleport_save_area_cs : public BasePacket 	// 텔레포트 좌표등록
	{
	public:
		int32_t tile_index{};

	public:
		mp_zone_teleport_save_area_cs() : BasePacket(mpe_cmd::zone_teleport_save_area_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tile_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_zone_teleport_save_area_sc : public BasePacket 	// 텔레포트 좌표등록
	{
	private:
		bool flag_reg_tel_info = false;
		mps_teleport_area reg_tel_info;	// 등록된 텔레포트 좌표 정보
		mps_teleport_area* p_reg_tel_info = nullptr;
	public:
		bool has_reg_tel_info() const
		{
			return flag_reg_tel_info;
		}
		mps_teleport_area* alloc_reg_tel_info()
		{
			flag_reg_tel_info = true;
			return &reg_tel_info;
		}
		const mps_teleport_area* get_reg_tel_info() const
		{
			if (true == flag_reg_tel_info)
			{
				if (nullptr == p_reg_tel_info)
				{
					return &reg_tel_info;
				}
				return p_reg_tel_info;
			}
			return nullptr;
		}
		void set_reg_tel_info(mps_teleport_area* in_reg_tel_info)
		{
			if (nullptr == p_reg_tel_info)
			{
				p_reg_tel_info = in_reg_tel_info;
				flag_reg_tel_info = true;
			}
		}
	private:
		bool flag_use_item = false;
		mps_item_add use_item;	// 사용한 아이템
		mps_item_add* p_use_item = nullptr;
	public:
		bool has_use_item() const
		{
			return flag_use_item;
		}
		mps_item_add* alloc_use_item()
		{
			flag_use_item = true;
			return &use_item;
		}
		const mps_item_add* get_use_item() const
		{
			if (true == flag_use_item)
			{
				if (nullptr == p_use_item)
				{
					return &use_item;
				}
				return p_use_item;
			}
			return nullptr;
		}
		void set_use_item(mps_item_add* in_use_item)
		{
			if (nullptr == p_use_item)
			{
				p_use_item = in_use_item;
				flag_use_item = true;
			}
		}

	public:
		mp_zone_teleport_save_area_sc() : BasePacket(mpe_cmd::zone_teleport_save_area_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_reg_tel_info);
			if (true == flag_reg_tel_info)
			{
				if (nullptr != p_reg_tel_info)
					protocol::SerializeType(pBuffer, p_reg_tel_info);
				else
					protocol::SerializeType(pBuffer, &reg_tel_info);
			}
			protocol::SerializeType(pBuffer, &flag_use_item);
			if (true == flag_use_item)
			{
				if (nullptr != p_use_item)
					protocol::SerializeType(pBuffer, p_use_item);
				else
					protocol::SerializeType(pBuffer, &use_item);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
