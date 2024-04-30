#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_received_mail.h"

namespace mir3d
{
	class mp_mail_received_cs : public BasePacket 
	{
	private:
		bool flag_mail = false;
		mps_received_mail mail;
		mps_received_mail* p_mail = nullptr;
	public:
		bool has_mail() const
		{
			return flag_mail;
		}
		mps_received_mail* alloc_mail()
		{
			flag_mail = true;
			return &mail;
		}
		const mps_received_mail* get_mail() const
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
		void set_mail(mps_received_mail* in_mail)
		{
			if (nullptr == p_mail)
			{
				p_mail = in_mail;
				flag_mail = true;
			}
		}

	public:
		mp_mail_received_cs() : BasePacket(mpe_cmd::mail_received_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
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
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_mail_received_sc : public BasePacket 
	{

	public:
		mp_mail_received_sc() : BasePacket(mpe_cmd::mail_received_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
