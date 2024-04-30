#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_zone_object_move_cs : public BasePacket 
	{

	public:
		mp_zone_object_move_cs() : BasePacket(mpe_cmd::zone_object_move_cs)
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

	class mp_zone_object_move_sc : public BasePacket 
	{
	public:
		int64_t uuid{};	// // 몬스터 uid
	public:
		mpe_move_type move_type{};	// // 이동 타입(mpe_move_type)
	public:
		int32_t end_cell{};	// // 도착 타일
	public:
		float move_time{};	// // 이동 시간

	public:
		mp_zone_object_move_sc() : BasePacket(mpe_cmd::zone_object_move_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uuid);
			protocol::SerializeEnum(pBuffer, &move_type);
			protocol::SerializeType(pBuffer, &end_cell);
			protocol::SerializeType(pBuffer, &move_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
