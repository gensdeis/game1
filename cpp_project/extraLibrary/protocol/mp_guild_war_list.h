#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_war.h"

namespace mir3d
{
	class mp_guild_war_list_cs : public BasePacket 	// 길드전쟁목록
	{

	public:
		mp_guild_war_list_cs() : BasePacket(mpe_cmd::guild_war_list_cs)
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

	class mp_guild_war_list_sc : public BasePacket 	// 길드전쟁목록
	{
	public:
		std::vector<mps_guild_war> list_guild_war{};

	public:
		mp_guild_war_list_sc() : BasePacket(mpe_cmd::guild_war_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_guild_war);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
