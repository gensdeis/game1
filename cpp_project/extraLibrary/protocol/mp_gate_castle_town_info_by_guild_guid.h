#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_castle_town_info_with_guild.h"

namespace mir3d
{
	class mp_gate_castle_town_info_by_guild_guid_cs : public BasePacket 
	{
	public:
		int64_t guid{};

	public:
		mp_gate_castle_town_info_by_guild_guid_cs() : BasePacket(mpe_cmd::gate_castle_town_info_by_guild_guid_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_castle_town_info_by_guild_guid_sc : public BasePacket 
	{
	public:
		std::vector<mps_castle_town_info_with_guild> info{};
	public:
		bool exists_save_bag{};

	public:
		mp_gate_castle_town_info_by_guild_guid_sc() : BasePacket(mpe_cmd::gate_castle_town_info_by_guild_guid_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &exists_save_bag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
