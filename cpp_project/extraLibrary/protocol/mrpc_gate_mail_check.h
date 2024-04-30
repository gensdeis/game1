#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_mail_check_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mrpc_gate_mail_check_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_mail_check_cs, tag)
		{
		}
		mrpc_gate_mail_check_cs() : RpcPacket(mpe_rpc_cmd::gate_mail_check_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_mail_check_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		uint8_t account_mail{};
	public:
		uint8_t server_mail{};
	public:
		uint8_t character_mail{};

	public:
		mrpc_gate_mail_check_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_mail_check_sc, tag)
		{
		}
		mrpc_gate_mail_check_sc() : RpcPacket(mpe_rpc_cmd::gate_mail_check_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &account_mail);
			protocol::SerializeType(pBuffer, &server_mail);
			protocol::SerializeType(pBuffer, &character_mail);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
