﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_lobby_character_delete_cs : public WebBasePacket 	// 캐릭터 삭제 로비(gate에서 삭제)
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string access_token{};
	public:
		mpe_os_type os_type{};

	public:
		mweb_lobby_character_delete_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeEnum(pBuffer, &os_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_lobby_character_delete_sc : public WebBasePacket 	// 캐릭터 삭제 로비(gate에서 삭제)
	{
	public:
		int32_t result{};
	public:
		int32_t delete_date{};

	public:
		mweb_lobby_character_delete_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &delete_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}