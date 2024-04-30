#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_zone_object_info.h"

namespace mir3d
{
	class mp_zone_drop_item_info_cs : public BasePacket 
	{

	public:
		mp_zone_drop_item_info_cs() : BasePacket(mpe_cmd::zone_drop_item_info_cs)
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

	class mp_zone_drop_item_info_sc : public BasePacket 
	{
	public:
		std::vector<mps_zone_object_info> info{};	// 맵의 아이템 정보
	public:
		uint8_t is_treasure_box_open{};	// 보물상자 오픈으로 나온 아이템인지 (0:false)

	public:
		mp_zone_drop_item_info_sc() : BasePacket(mpe_cmd::zone_drop_item_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &is_treasure_box_open);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
