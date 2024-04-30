#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_castle_town_start_specialties_delivery_cs : public BasePacket 	// 장원 특산품 납품 시작
	{
	public:
		int64_t nuid{};
	public:
		int32_t town_id{};
	public:
		mpe_castle_town_specialties_pos specialties_pos{};	// 특산품 작업

	public:
		mp_castle_town_start_specialties_delivery_cs() : BasePacket(mpe_cmd::castle_town_start_specialties_delivery_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nuid);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeEnum(pBuffer, &specialties_pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_castle_town_start_specialties_delivery_sc : public BasePacket 	// 장원 특산품 납품 시작
	{
	public:
		mpe_castle_town_specialties_pos specialties_pos{};	// 특산품 작업
	public:
		int64_t end_time{};	// 종료시간

	public:
		mp_castle_town_start_specialties_delivery_sc() : BasePacket(mpe_cmd::castle_town_start_specialties_delivery_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &specialties_pos);
			protocol::SerializeType(pBuffer, &end_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
