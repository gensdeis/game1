#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_guild_accept_member_cs : public BasePacket 
	{
	public:
		bool accept{};
	public:
		int64_t target_uid{};

	public:
		mp_guild_accept_member_cs() : BasePacket(mpe_cmd::guild_accept_member_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &accept);
			protocol::SerializeType(pBuffer, &target_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_accept_member_sc : public BasePacket 
	{
	public:
		bool accept{};
	public:
		int64_t target_uid{};

	public:
		mp_guild_accept_member_sc() : BasePacket(mpe_cmd::guild_accept_member_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &accept);
			protocol::SerializeType(pBuffer, &target_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
