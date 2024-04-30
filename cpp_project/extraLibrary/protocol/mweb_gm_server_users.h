﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mgms_server_user.h"

namespace mir3d
{
	class mweb_gm_server_users_cs : public WebBasePacket 
	{
	public:
		std::string access_token{};
	public:
		int32_t gid{};

	public:
		mweb_gm_server_users_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_server_users_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	public:
		std::vector<mgms_server_user> list_user{};

	public:
		mweb_gm_server_users_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &list_user);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}