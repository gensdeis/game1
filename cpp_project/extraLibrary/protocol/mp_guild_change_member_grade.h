#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_member.h"

namespace mir3d
{
	class mp_guild_change_member_grade_cs : public BasePacket 
	{
	public:
		int64_t target_cuid{};
	public:
		mpe_guild_member_grade grade{};

	public:
		mp_guild_change_member_grade_cs() : BasePacket(mpe_cmd::guild_change_member_grade_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeEnum(pBuffer, &grade);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_change_member_grade_sc : public BasePacket 
	{
	public:
		std::vector<mps_guild_member> list_member{};

	public:
		mp_guild_change_member_grade_sc() : BasePacket(mpe_cmd::guild_change_member_grade_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_member);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
