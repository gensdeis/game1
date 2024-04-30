#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_ally_cancel_cs : public BasePacket 	// "동맹 해제"
	{
	public:
		int64_t my_guid{};	// "요청 문파 UID"
	public:
		int64_t target_guid{};	// "대상 문파 UID"

	public:
		mp_guild_ally_cancel_cs() : BasePacket(mpe_cmd::guild_ally_cancel_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &my_guid);
			protocol::SerializeType(pBuffer, &target_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_ally_cancel_sc : public BasePacket 	// "동맹 해제"
	{
	public:
		int64_t target_guid{};	// "동맹 해제된 문파uid"
	public:
		int64_t cancel_time{};	// "동맹해제시간"

	public:
		mp_guild_ally_cancel_sc() : BasePacket(mpe_cmd::guild_ally_cancel_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_guid);
			protocol::SerializeType(pBuffer, &cancel_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
