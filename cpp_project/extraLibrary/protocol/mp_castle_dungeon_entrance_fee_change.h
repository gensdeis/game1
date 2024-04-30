#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_castle_dungeon_entrance_fee_change_cs : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t nuid{};
	public:
		int64_t guid{};
	public:
		mpe_siege_castle_type castle_type{};	// 세율 변경 성 type
	public:
		int32_t entrance_fee{};

	public:
		mp_castle_dungeon_entrance_fee_change_cs() : BasePacket(mpe_cmd::castle_dungeon_entrance_fee_change_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &entrance_fee);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_castle_dungeon_entrance_fee_change_sc : public BasePacket 
	{
	public:
		mpe_siege_castle_type castle_type{};	// 세율 변경 성 type
	public:
		int32_t entrance_fee{};

	public:
		mp_castle_dungeon_entrance_fee_change_sc() : BasePacket(mpe_cmd::castle_dungeon_entrance_fee_change_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &entrance_fee);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
