#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_equip_list.h"

namespace mir3d
{
	class mp_zone_character_item_equip_cs : public BasePacket 
	{

	public:
		mp_zone_character_item_equip_cs() : BasePacket(mpe_cmd::zone_character_item_equip_cs)
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

	class mp_zone_character_item_equip_sc : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		mpe_equip_flag flag{};	// [default = equip];
	private:
		bool flag_info = false;
		mps_equip_list info;
		mps_equip_list* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mps_equip_list* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mps_equip_list* get_info() const
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
		void set_info(mps_equip_list* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		int32_t reflection_id{};	// 화신
	public:
		uint16_t customizing_data{};	// 커마 정보

	public:
		mp_zone_character_item_equip_sc() : BasePacket(mpe_cmd::zone_character_item_equip_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &flag);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeType(pBuffer, &reflection_id);
			protocol::SerializeType(pBuffer, &customizing_data);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
