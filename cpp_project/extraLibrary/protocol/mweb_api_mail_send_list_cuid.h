#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mail_item.h"

namespace mir3d
{
	class mweb_api_mail_send_list_cuid_cs : public WebBasePacket 
	{
	public:
		std::vector<int64_t> list_uid{};
	public:
		int64_t muid{};
	public:
		mpe_mail_type mail_type{};
	public:
		int32_t tid{};
	public:
		int32_t expir_date{};
	public:
		std::vector<mps_mail_item> info{};
	public:
		std::string title_text{};
	public:
		std::string content_text{};

	public:
		mweb_api_mail_send_list_cuid_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_uid);
			protocol::SerializeType(pBuffer, &muid);
			protocol::SerializeEnum(pBuffer, &mail_type);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &expir_date);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &title_text);
			protocol::SerializeType(pBuffer, &content_text);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_mail_send_list_cuid_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_api_mail_send_list_cuid_sc() : WebBasePacket()
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
