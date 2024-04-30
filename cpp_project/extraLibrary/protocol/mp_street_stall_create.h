#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_street_stall_create_cs : public BasePacket 	// // 개인 노점 생성
	{
	public:
		int32_t map_object_table_id{};	// // map object table id

	public:
		mp_street_stall_create_cs() : BasePacket(mpe_cmd::street_stall_create_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &map_object_table_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_street_stall_create_sc : public BasePacket 	// // 개인 노점 생성
	{
	public:
		int64_t cuid{};
	public:
		int32_t map_object_table_id{};	// // map object table id
	public:
		mpe_character_action action{};

	public:
		mp_street_stall_create_sc() : BasePacket(mpe_cmd::street_stall_create_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &map_object_table_id);
			protocol::SerializeEnum(pBuffer, &action);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
