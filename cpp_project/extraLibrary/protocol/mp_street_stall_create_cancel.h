﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_street_stall_create_cancel_cs : public BasePacket 	// // 개인 노점 생성 취소
	{

	public:
		mp_street_stall_create_cancel_cs() : BasePacket(mpe_cmd::street_stall_create_cancel_cs)
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

	class mp_street_stall_create_cancel_sc : public BasePacket 	// // 개인 노점 생성 취소
	{
	public:
		int32_t map_object_table_id{};	// // map object table id
	public:
		int64_t cuid{};	// // 점유해제 캐릭터 uid

	public:
		mp_street_stall_create_cancel_sc() : BasePacket(mpe_cmd::street_stall_create_cancel_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &map_object_table_id);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}