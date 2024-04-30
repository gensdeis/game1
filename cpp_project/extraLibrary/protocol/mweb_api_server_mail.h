#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mail.h"

namespace mir3d
{
	class mweb_api_server_mail_cs : public WebBasePacket 
	{
	public:
		int64_t uid{};
	public:
		int32_t mail_type{};

	public:
		mweb_api_server_mail_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &mail_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_server_mail_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};
	public:
		std::vector<mps_mail> list_mail{};

	public:
		mweb_api_server_mail_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &list_mail);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
