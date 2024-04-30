#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_approve_send_transaction_cs : public RpcPacket 	// approve 트랜잭션 전송
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string signature{};	// 유저 사인값
	public:
		mrpce_token_type_client token_type{};	// 토큰 타입
	public:
		mrpce_contract_type contract_type{};	// 컨트랙트 타입

	public:
		mrpc_approve_send_transaction_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::approve_send_transaction_cs, tag)
		{
		}
		mrpc_approve_send_transaction_cs() : RpcPacket(mpe_rpc_cmd::approve_send_transaction_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &signature);
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeEnum(pBuffer, &contract_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_approve_send_transaction_sc : public RpcPacket 	// approve 트랜잭션 전송
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mrpc_approve_send_transaction_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::approve_send_transaction_sc, tag)
		{
		}
		mrpc_approve_send_transaction_sc() : RpcPacket(mpe_rpc_cmd::approve_send_transaction_sc)
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

}
