#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_town_boss_summon_cs : public BasePacket 
	{
	public:
		std::vector<int32_t> list_item_id{};	// // 장원 - 보스소환 아이템 table id

	public:
		mp_guild_town_boss_summon_cs() : BasePacket(mpe_cmd::guild_town_boss_summon_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_item_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_town_boss_summon_sc : public BasePacket 
	{

	public:
		mp_guild_town_boss_summon_sc() : BasePacket(mpe_cmd::guild_town_boss_summon_sc)
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

}
