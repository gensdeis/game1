﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_staking_make_tx_cs : public RpcPacket 	// 스테이킹 트랜잭션 생성
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		mrpce_token_type_client token_type{};	// 스테이킹 타입 (1: 드론, 2:하이드라)
	public:
		std::string amount{};	// 수량
	public:
		std::string user_wallet{};	// 유저 지갑 주소

	public:
		mrpc_staking_make_tx_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::staking_make_tx_cs, tag)
		{
		}
		mrpc_staking_make_tx_cs() : RpcPacket(mpe_rpc_cmd::staking_make_tx_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeType(pBuffer, &amount);
			protocol::SerializeType(pBuffer, &user_wallet);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_staking_make_tx_sc : public RpcPacket 	// 스테이킹 트랜잭션 생성
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		std::string hash{};	// 해시값

	public:
		mrpc_staking_make_tx_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::staking_make_tx_sc, tag)
		{
		}
		mrpc_staking_make_tx_sc() : RpcPacket(mpe_rpc_cmd::staking_make_tx_sc)
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