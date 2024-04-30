#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_claim_make_tx_cs : public RpcPacket 	// 보상청구 트랜잭션 생성
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string user_wallet{};	// 유저 지갑 주소

	public:
		mrpc_claim_make_tx_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::claim_make_tx_cs, tag)
		{
		}
		mrpc_claim_make_tx_cs() : RpcPacket(mpe_rpc_cmd::claim_make_tx_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &user_wallet);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_claim_make_tx_sc : public RpcPacket 	// 보상청구 트랜잭션 생성
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		std::string hash{};	// 해시값

	public:
		mrpc_claim_make_tx_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::claim_make_tx_sc, tag)
		{
		}
		mrpc_claim_make_tx_sc() : RpcPacket(mpe_rpc_cmd::claim_make_tx_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &hash);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
