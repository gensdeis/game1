﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_gm_lobby_enable_cs : public WebBasePacket 
	{
	public:
		std::string access_token{};
	public:
		int32_t gid{};
	public:
		bool state{};

	public:
		mweb_gm_lobby_enable_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_lobby_enable_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	public:
		bool state{};

	public:
		mweb_gm_lobby_enable_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}