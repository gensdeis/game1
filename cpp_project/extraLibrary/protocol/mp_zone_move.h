﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_zone_move_cs : public BasePacket 
	{
	public:
		int32_t curr_cell{};	// // 현재 타일
	public:
		mpe_direction direction{};	// // 방향(mpe_direction)
	public:
		mpe_move_type type{};	// // walk / run / stop(mpe_move_type)
	public:
		float move_time{};	// // 도착 시간(클라이언트 사용)

	public:
		mp_zone_move_cs() : BasePacket(mpe_cmd::zone_move_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &curr_cell);
			protocol::SerializeEnum(pBuffer, &direction);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &move_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_zone_move_sc : public BasePacket 
	{
	public:
		int64_t uuid{};	// // 캐릭터 uid
	public:
		int32_t curr_cell{};	// // 현재 타일
	public:
		mpe_direction direction{};	// // 방향(mpe_direction)
	public:
		mpe_move_type move_type{};	// // walk / run / stop(mpe_move_type)
	public:
		float move_time{};	// // 도착 시간(클라이언트 사용)
	public:
		mpe_error error{};	// // 에러(mpe_error)
	public:
		int64_t server_time{};	// // 서버 체크용 시간

	public:
		mp_zone_move_sc() : BasePacket(mpe_cmd::zone_move_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uuid);
			protocol::SerializeType(pBuffer, &curr_cell);
			protocol::SerializeEnum(pBuffer, &direction);
			protocol::SerializeEnum(pBuffer, &move_type);
			protocol::SerializeType(pBuffer, &move_time);
			protocol::SerializeEnum(pBuffer, &error);
			protocol::SerializeType(pBuffer, &server_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}