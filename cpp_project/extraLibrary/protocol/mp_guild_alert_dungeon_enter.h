#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_alert_dungeon_enter_cs : public BasePacket 	// 던전입장알림
	{

	public:
		mp_guild_alert_dungeon_enter_cs() : BasePacket(mpe_cmd::guild_alert_dungeon_enter_cs)
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

	class mp_guild_alert_dungeon_enter_sc : public BasePacket 	// 던전입장알림
	{
	public:
		std::string nickname{};	// 길드원이름

	public:
		mp_guild_alert_dungeon_enter_sc() : BasePacket(mpe_cmd::guild_alert_dungeon_enter_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nickname);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
