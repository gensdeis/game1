#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_member_look_info.h"

namespace mir3d
{
	class mp_siege_warfare_victory_character_info_cs : public BasePacket 
	{

	public:
		mp_siege_warfare_victory_character_info_cs() : BasePacket(mpe_cmd::siege_warfare_victory_character_info_cs)
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

	class mp_siege_warfare_victory_character_info_sc : public BasePacket 
	{
	public:
		std::vector<mps_guild_member_look_info> guild_member_look_list{};

	public:
		mp_siege_warfare_victory_character_info_sc() : BasePacket(mpe_cmd::siege_warfare_victory_character_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guild_member_look_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
