#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_mail_check_cs : public BasePacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mp_gate_mail_check_cs() : BasePacket(mpe_cmd::gate_mail_check_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_mail_check_sc : public BasePacket 
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
		mp_gate_mail_check_sc() : BasePacket(mpe_cmd::gate_mail_check_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &account_mail);
			protocol::SerializeType(pBuffer, &server_mail);
			protocol::SerializeType(pBuffer, &character_mail);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
