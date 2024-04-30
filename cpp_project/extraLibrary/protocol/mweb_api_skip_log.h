﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_api_skip_log_cs : public WebBasePacket 
	{
	public:
		std::vector<int32_t> list_type{};

	public:
		mweb_api_skip_log_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_skip_log_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_api_skip_log_sc() : WebBasePacket()
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