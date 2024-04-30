#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mail.h"

namespace mir3d
{
	class mp_gate_mail_list_cs : public BasePacket 	// 메일 목록 가져오기
	{
	public:
		int64_t uid{};
	public:
		mpe_mail_type mail_type{};

	public:
		mp_gate_mail_list_cs() : BasePacket(mpe_cmd::gate_mail_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeEnum(pBuffer, &mail_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_mail_list_sc : public BasePacket 	// 메일 목록 가져오기
	{
	public:
		std::vector<mps_mail> list_mail{};
	public:
		mpe_mail_type mail_type{};

	public:
		mp_gate_mail_list_sc() : BasePacket(mpe_cmd::gate_mail_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_mail);
			protocol::SerializeEnum(pBuffer, &mail_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
