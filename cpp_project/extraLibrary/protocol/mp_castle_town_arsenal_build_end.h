#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_castle_town_arsenal_build_end_cs : public BasePacket 	// 병기창 작업 완료 처리
	{
	public:
		int64_t nuid{};
	public:
		int32_t town_id{};

	public:
		mp_castle_town_arsenal_build_end_cs() : BasePacket(mpe_cmd::castle_town_arsenal_build_end_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nuid);
			protocol::SerializeType(pBuffer, &town_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_castle_town_arsenal_build_end_sc : public BasePacket 	// 병기창 작업 완료 처리
	{
	public:
		int32_t build_item_id{};	// 생산된 아이템 아이디

	public:
		mp_castle_town_arsenal_build_end_sc() : BasePacket(mpe_cmd::castle_town_arsenal_build_end_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &build_item_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
