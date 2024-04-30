#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_mail_open_cs : public BasePacket 	// 우편 열기
	{
	public:
		int64_t muid{};
	public:
		mpe_mail_type mail_type{};

	public:
		mp_mail_open_cs() : BasePacket(mpe_cmd::mail_open_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &muid);
			protocol::SerializeEnum(pBuffer, &mail_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_mail_open_sc : public BasePacket 	// 우편 열기
	{
	public:
		int64_t open_muid{};

	public:
		mp_mail_open_sc() : BasePacket(mpe_cmd::mail_open_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &open_muid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
