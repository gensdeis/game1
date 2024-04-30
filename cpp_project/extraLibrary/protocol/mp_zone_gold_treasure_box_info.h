#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_zone_gold_treasure_box_info_cs : public BasePacket 
	{

	public:
		mp_zone_gold_treasure_box_info_cs() : BasePacket(mpe_cmd::zone_gold_treasure_box_info_cs)
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

	class mp_zone_gold_treasure_box_info_sc : public BasePacket 
	{
	public:
		std::vector<int64_t> keep_time{};	// 남은 시간

	public:
		mp_zone_gold_treasure_box_info_sc() : BasePacket(mpe_cmd::zone_gold_treasure_box_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &keep_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
