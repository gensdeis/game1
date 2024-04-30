#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_teleport_area.h"
#include "struct/mps_teleport_area.h"

namespace mir3d
{
	class mp_zone_teleport_save_area_delete_cs : public BasePacket 	// 텔레포트 좌표삭제
	{
	private:
		bool flag_del_tel_info = false;
		mps_teleport_area del_tel_info;	// 삭제할 텔레포트 좌표 정보
		mps_teleport_area* p_del_tel_info = nullptr;
	public:
		bool has_del_tel_info() const
		{
			return flag_del_tel_info;
		}
		mps_teleport_area* alloc_del_tel_info()
		{
			flag_del_tel_info = true;
			return &del_tel_info;
		}
		const mps_teleport_area* get_del_tel_info() const
		{
			if (true == flag_del_tel_info)
			{
				if (nullptr == p_del_tel_info)
				{
					return &del_tel_info;
				}
				return p_del_tel_info;
			}
			return nullptr;
		}
		void set_del_tel_info(mps_teleport_area* in_del_tel_info)
		{
			if (nullptr == p_del_tel_info)
			{
				p_del_tel_info = in_del_tel_info;
				flag_del_tel_info = true;
			}
		}

	public:
		mp_zone_teleport_save_area_delete_cs() : BasePacket(mpe_cmd::zone_teleport_save_area_delete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_del_tel_info);
			if (true == flag_del_tel_info)
			{
				if (nullptr != p_del_tel_info)
					protocol::SerializeType(pBuffer, p_del_tel_info);
				else
					protocol::SerializeType(pBuffer, &del_tel_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_zone_teleport_save_area_delete_sc : public BasePacket 	// 텔레포트 좌표삭제
	{
	private:
		bool flag_del_tel_info = false;
		mps_teleport_area del_tel_info;	// 삭제된 텔레포트 좌표 정보
		mps_teleport_area* p_del_tel_info = nullptr;
	public:
		bool has_del_tel_info() const
		{
			return flag_del_tel_info;
		}
		mps_teleport_area* alloc_del_tel_info()
		{
			flag_del_tel_info = true;
			return &del_tel_info;
		}
		const mps_teleport_area* get_del_tel_info() const
		{
			if (true == flag_del_tel_info)
			{
				if (nullptr == p_del_tel_info)
				{
					return &del_tel_info;
				}
				return p_del_tel_info;
			}
			return nullptr;
		}
		void set_del_tel_info(mps_teleport_area* in_del_tel_info)
		{
			if (nullptr == p_del_tel_info)
			{
				p_del_tel_info = in_del_tel_info;
				flag_del_tel_info = true;
			}
		}

	public:
		mp_zone_teleport_save_area_delete_sc() : BasePacket(mpe_cmd::zone_teleport_save_area_delete_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_del_tel_info);
			if (true == flag_del_tel_info)
			{
				if (nullptr != p_del_tel_info)
					protocol::SerializeType(pBuffer, p_del_tel_info);
				else
					protocol::SerializeType(pBuffer, &del_tel_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
