#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_zone_object_info.h"

namespace mir3d
{
	class mp_zone_object_dead_cs : public BasePacket 
	{

	public:
		mp_zone_object_dead_cs() : BasePacket(mpe_cmd::zone_object_dead_cs)
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

	class mp_zone_object_dead_sc : public BasePacket 
	{
	public:
		int64_t uid{};	//  몬스터 uid
	public:
		bool explode{};	// 폭발 드랍 유무
	private:
		bool flag_info = false;
		mps_zone_object_info info;	// 맵의 아이템 정보
		mps_zone_object_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_zone_object_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_zone_object_info* get_info() const
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
		void set_info(mps_zone_object_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int32_t type{};	// type
	public:
		mpe_dead_reason reason{};	// 죽음 종류

	public:
		mp_zone_object_dead_sc() : BasePacket(mpe_cmd::zone_object_dead_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &explode);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeEnum(pBuffer, &reason);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
