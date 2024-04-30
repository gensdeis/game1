#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_ally_info.h"

namespace mir3d
{
	class mp_guild_ally_list_cs : public BasePacket 	// 문파 동맹 목록
	{
	public:
		int64_t my_guid{};	// 내 문파 UID

	public:
		mp_guild_ally_list_cs() : BasePacket(mpe_cmd::guild_ally_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &my_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_ally_list_sc : public BasePacket 	// 문파 동맹 목록
	{
	public:
		std::vector<mps_guild_ally_info> ally_list{};	// 동맹목록

	public:
		mp_guild_ally_list_sc() : BasePacket(mpe_cmd::guild_ally_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ally_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
