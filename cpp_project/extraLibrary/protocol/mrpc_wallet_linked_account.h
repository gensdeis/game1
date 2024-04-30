#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_wallet_linked_account_cs : public RpcPacket 	// 지갑 계정 연동
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string wallet_address{};	// 서버로부터 전달받은 월렛 주소

	public:
		mrpc_wallet_linked_account_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::wallet_linked_account_cs, tag)
		{
		}
		mrpc_wallet_linked_account_cs() : RpcPacket(mpe_rpc_cmd::wallet_linked_account_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &wallet_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_wallet_linked_account_sc : public RpcPacket 	// 지갑 계정 연동
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string request_wallet_address{};	// 서버로부터 전달받은 월렛 주소
	public:
		std::string response_wallet_address{};	// 월렛 주소

	public:
		mrpc_wallet_linked_account_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::wallet_linked_account_sc, tag)
		{
		}
		mrpc_wallet_linked_account_sc() : RpcPacket(mpe_rpc_cmd::wallet_linked_account_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &request_wallet_address);
			protocol::SerializeType(pBuffer, &response_wallet_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
