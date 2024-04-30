#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mail_item.h"

namespace mir3d
{
	class mp_mail_send_cs : public BasePacket 	// 메일 보내기
	{
	public:
		int64_t uid{};
	public:
		int64_t muid{};
	public:
		mpe_mail_type mail_type{};
	public:
		int32_t tid{};
	public:
		int32_t expire_date{};
	public:
		std::vector<mps_mail_item> info{};

	public:
		mp_mail_send_cs() : BasePacket(mpe_cmd::mail_send_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &muid);
			protocol::SerializeEnum(pBuffer, &mail_type);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &expire_date);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_mail_send_sc : public BasePacket 	// 메일 보내기
	{
	public:
		bool result{};

	public:
		mp_mail_send_sc() : BasePacket(mpe_cmd::mail_send_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
