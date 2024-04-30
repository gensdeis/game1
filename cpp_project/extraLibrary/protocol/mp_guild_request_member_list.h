﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_request_member.h"

namespace mir3d
{
	class mp_guild_request_member_list_cs : public BasePacket 
	{

	public:
		mp_guild_request_member_list_cs() : BasePacket(mpe_cmd::guild_request_member_list_cs)
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

	class mp_guild_request_member_list_sc : public BasePacket 
	{
	public:
		std::vector<mps_guild_request_member> list_request_member{};

	public:
		mp_guild_request_member_list_sc() : BasePacket(mpe_cmd::guild_request_member_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_request_member);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
