#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_promo_verify_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::string player_key{};
	public:
		int64_t account_uid{};
	public:
		int64_t character_uid{};
	public:
		std::string user_agent{};
	public:
		std::string product_id{};
	public:
		std::string purchase_token{};

	public:
		mrpc_gate_promo_verify_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_promo_verify_cs, tag)
		{
		}
		mrpc_gate_promo_verify_cs() : RpcPacket(mpe_rpc_cmd::gate_promo_verify_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &player_key);
			protocol::SerializeType(pBuffer, &account_uid);
			protocol::SerializeType(pBuffer, &character_uid);
			protocol::SerializeType(pBuffer, &user_agent);
			protocol::SerializeType(pBuffer, &product_id);
			protocol::SerializeType(pBuffer, &purchase_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_promo_verify_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t code{};
	public:
		std::string pay_id{};

	public:
		mrpc_gate_promo_verify_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_promo_verify_sc, tag)
		{
		}
		mrpc_gate_promo_verify_sc() : RpcPacket(mpe_rpc_cmd::gate_promo_verify_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &code);
			protocol::SerializeType(pBuffer, &pay_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
