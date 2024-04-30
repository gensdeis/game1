#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_mail_check_cs : public WebBasePacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mweb_mail_check_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_mail_check_sc : public WebBasePacket 
	{
	public:
		int32_t result{};
	public:
		uint8_t account_mail{};
	public:
		uint8_t server_mail{};
	public:
		uint8_t character_mail{};

	public:
		mweb_mail_check_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &account_mail);
			protocol::SerializeType(pBuffer, &server_mail);
			protocol::SerializeType(pBuffer, &character_mail);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
