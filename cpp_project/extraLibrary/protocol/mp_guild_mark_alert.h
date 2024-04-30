#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_mark_alert_cs : public BasePacket 
	{

	public:
		mp_guild_mark_alert_cs() : BasePacket(mpe_cmd::guild_mark_alert_cs)
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

	class mp_guild_mark_alert_sc : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		std::string guild_name{};

	public:
		mp_guild_mark_alert_sc() : BasePacket(mpe_cmd::guild_mark_alert_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &guild_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
