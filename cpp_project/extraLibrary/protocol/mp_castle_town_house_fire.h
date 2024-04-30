#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_castle_town_house_fire_cs : public BasePacket 	// 장원 npc 해고
	{
	public:
		int64_t nuid{};
	public:
		int32_t town_id{};
	public:
		mpe_castle_town_detail_pos house_pos{};	// house 고용 타입

	public:
		mp_castle_town_house_fire_cs() : BasePacket(mpe_cmd::castle_town_house_fire_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nuid);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeEnum(pBuffer, &house_pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_castle_town_house_fire_sc : public BasePacket 	// 장원 npc 해고
	{
	public:
		int32_t town_id{};
	public:
		mpe_castle_town_detail_pos house_pos{};	// house 고용 타입

	public:
		mp_castle_town_house_fire_sc() : BasePacket(mpe_cmd::castle_town_house_fire_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeEnum(pBuffer, &house_pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
