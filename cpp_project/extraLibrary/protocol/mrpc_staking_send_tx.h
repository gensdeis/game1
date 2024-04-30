#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_staking_send_tx_cs : public RpcPacket 	// 스테이킹 트랜잭션 전달
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
		std::string signature{};	// 사인값
	public:
		std::string user_wallet{};	// 유저 지갑 주소
	public:
		int32_t server_gid{};
	public:
		int32_t server_index{};
	public:
		mrpce_server_type server_type{};
	public:
		uint8_t character_tid{};
	public:
		int32_t character_level{};
	public:
		int32_t character_power{};
	public:
		std::string nickname{};

	public:
		mrpc_staking_send_tx_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::staking_send_tx_cs, tag)
		{
		}
		mrpc_staking_send_tx_cs() : RpcPacket(mpe_rpc_cmd::staking_send_tx_cs)
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
			protocol::SerializeType(pBuffer, &signature);
			protocol::SerializeType(pBuffer, &user_wallet);
			protocol::SerializeType(pBuffer, &server_gid);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &character_tid);
			protocol::SerializeType(pBuffer, &character_level);
			protocol::SerializeType(pBuffer, &character_power);
			protocol::SerializeType(pBuffer, &nickname);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_staking_send_tx_sc : public RpcPacket 	// 스테이킹 트랜잭션 전달
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};

	public:
		mrpc_staking_send_tx_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::staking_send_tx_sc, tag)
		{
		}
		mrpc_staking_send_tx_sc() : RpcPacket(mpe_rpc_cmd::staking_send_tx_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
