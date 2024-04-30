#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_member_pvp_info.h"

namespace mir3d
{
	class mp_guild_member_pvp_info_cs : public BasePacket 	// 문파원 PVP 기록 정보
	{

	public:
		mp_guild_member_pvp_info_cs() : BasePacket(mpe_cmd::guild_member_pvp_info_cs)
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

	class mp_guild_member_pvp_info_sc : public BasePacket 	// 문파원 PVP 기록 정보
	{
	public:
		std::vector<mps_guild_member_pvp_info> pvp_info{};	// pvp 기록 정보

	public:
		mp_guild_member_pvp_info_sc() : BasePacket(mpe_cmd::guild_member_pvp_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &pvp_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
