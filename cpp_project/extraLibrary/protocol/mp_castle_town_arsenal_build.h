#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_castle_town_arsenal_build_cs : public BasePacket 	// 병기창 무기 생산 요청
	{
	public:
		int64_t nuid{};
	public:
		int32_t town_id{};
	public:
		int32_t build_id{};	// 생산할 공성무기 테이블(arsenal_build_table) 아이디

	public:
		mp_castle_town_arsenal_build_cs() : BasePacket(mpe_cmd::castle_town_arsenal_build_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nuid);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeType(pBuffer, &build_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_castle_town_arsenal_build_sc : public BasePacket 	// 병기창 무기 생산 요청
	{
	public:
		mpe_siege_castle_type castle_type{};
	public:
		int32_t town_id{};
	public:
		int32_t build_id{};

	public:
		mp_castle_town_arsenal_build_sc() : BasePacket(mpe_cmd::castle_town_arsenal_build_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeType(pBuffer, &build_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
