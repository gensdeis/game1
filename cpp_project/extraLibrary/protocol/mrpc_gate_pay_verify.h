#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_pay_verify_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::string pay_id{};
	public:
		std::string player_key{};
	public:
		int64_t account_uid{};
	public:
		int64_t character_uid{};
	public:
		std::string user_agent{};
	public:
		std::string purchase_token{};
	public:
		std::string store_type{};
	public:
		std::string store_appid{};

	public:
		mrpc_gate_pay_verify_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_pay_verify_cs, tag)
		{
		}
		mrpc_gate_pay_verify_cs() : RpcPacket(mpe_rpc_cmd::gate_pay_verify_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &pay_id);
			protocol::SerializeType(pBuffer, &player_key);
			protocol::SerializeType(pBuffer, &account_uid);
			protocol::SerializeType(pBuffer, &character_uid);
			protocol::SerializeType(pBuffer, &user_agent);
			protocol::SerializeType(pBuffer, &purchase_token);
			protocol::SerializeType(pBuffer, &store_type);
			protocol::SerializeType(pBuffer, &store_appid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_pay_verify_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t code{};
	public:
		int32_t purchase_quantity{};

	public:
		mrpc_gate_pay_verify_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_pay_verify_sc, tag)
		{
		}
		mrpc_gate_pay_verify_sc() : RpcPacket(mpe_rpc_cmd::gate_pay_verify_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &code);
			protocol::SerializeType(pBuffer, &purchase_quantity);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
