﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_api_guild_level_edit_cs : public WebBasePacket 
	{
	public:
		int64_t guid{};
	public:
		int32_t level{};
	public:
		int32_t exp{};

	public:
		mweb_api_guild_level_edit_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &exp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_guild_level_edit_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_api_guild_level_edit_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
