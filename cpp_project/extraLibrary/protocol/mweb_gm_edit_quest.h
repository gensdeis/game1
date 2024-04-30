﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_gm_edit_quest_cs : public WebBasePacket 
	{
	public:
		std::string access_token{};
	public:
		int32_t gid{};
	public:
		int64_t cuid{};
	public:
		uint16_t quest_tid{};
	public:
		mpe_quest_state state{};
	public:
		int32_t object_count{};

	public:
		mweb_gm_edit_quest_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &quest_tid);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &object_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_edit_quest_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_gm_edit_quest_sc() : WebBasePacket()
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
