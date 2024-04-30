#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_ally_request_deny_cs : public BasePacket 	// 문파 동맹 요청 거절
	{
	public:
		int64_t target_guid{};	// 동맹 요청 문파 UID

	public:
		mp_guild_ally_request_deny_cs() : BasePacket(mpe_cmd::guild_ally_request_deny_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_ally_request_deny_sc : public BasePacket 	// 문파 동맹 요청 거절
	{
	public:
		int64_t deny_guid{};	// 거절된문파uid

	public:
		mp_guild_ally_request_deny_sc() : BasePacket(mpe_cmd::guild_ally_request_deny_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &deny_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
