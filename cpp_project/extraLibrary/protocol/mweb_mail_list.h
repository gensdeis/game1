#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mail.h"

namespace mir3d
{
	class mweb_mail_list_cs : public WebBasePacket 	// 메일 목록 가져오기
	{
	public:
		int64_t uid{};
	public:
		mpe_mail_type mail_type{};

	public:
		mweb_mail_list_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeEnum(pBuffer, &mail_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_mail_list_sc : public WebBasePacket 	// 메일 목록 가져오기
	{
	public:
		std::vector<mps_mail> list_mail{};
	public:
		mpe_mail_type mail_type{};

	public:
		mweb_mail_list_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_mail);
			protocol::SerializeEnum(pBuffer, &mail_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
