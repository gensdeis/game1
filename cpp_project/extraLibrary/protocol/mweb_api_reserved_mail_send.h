#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mail.h"

namespace mir3d
{
	class mweb_api_reserved_mail_send_cs : public WebBasePacket 
	{
	public:
		mpe_mail_type mail_type{};
	private:
		bool flag_mail = false;
		mps_mail mail;
		mps_mail* p_mail = nullptr;
	public:
		bool has_mail() const
		{
			return flag_mail;
		}
		mps_mail* alloc_mail()
		{
			flag_mail = true;
			return &mail;
		}
		const mps_mail* get_mail() const
		{
			if (true == flag_mail)
			{
				if (nullptr == p_mail)
				{
					return &mail;
				}
				return p_mail;
			}
			return nullptr;
		}
		void set_mail(mps_mail* in_mail)
		{
			if (nullptr == p_mail)
			{
				p_mail = in_mail;
				flag_mail = true;
			}
		}

	public:
		mweb_api_reserved_mail_send_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &mail_type);
			protocol::SerializeType(pBuffer, &flag_mail);
			if (true == flag_mail)
			{
				if (nullptr != p_mail)
					protocol::SerializeType(pBuffer, p_mail);
				else
					protocol::SerializeType(pBuffer, &mail);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_api_reserved_mail_send_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};

	public:
		mweb_api_reserved_mail_send_sc() : WebBasePacket()
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
