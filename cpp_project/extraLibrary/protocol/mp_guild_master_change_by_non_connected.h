#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_member.h"

namespace mir3d
{
	class mp_guild_master_change_by_non_connected_cs : public BasePacket 	// 문파장 장기 미접속 강제 위임 요청
	{
	public:
		int64_t request_cuid{};	// "요청문파원"

	public:
		mp_guild_master_change_by_non_connected_cs() : BasePacket(mpe_cmd::guild_master_change_by_non_connected_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &request_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_master_change_by_non_connected_sc : public BasePacket 	// 문파장 장기 미접속 강제 위임 요청
	{
	public:
		mpe_guild_member_grade grade{};	// "결과 등급 값"
	public:
		std::vector<mps_guild_member> list_member{};	// "문파장변경후 길드멤버 목록"

	public:
		mp_guild_master_change_by_non_connected_sc() : BasePacket(mpe_cmd::guild_master_change_by_non_connected_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &grade);
			protocol::SerializeType(pBuffer, &list_member);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
