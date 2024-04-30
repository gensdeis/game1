#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_get_contract_address_cs : public RpcPacket 	// contract server 주소 요청
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mrpc_get_contract_address_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::get_contract_address_cs, tag)
		{
		}
		mrpc_get_contract_address_cs() : RpcPacket(mpe_rpc_cmd::get_contract_address_cs)
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

	class mrpc_get_contract_address_sc : public RpcPacket 	// contract server 주소 요청
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string contract_address{};	// 컨트랙트 address

	public:
		mrpc_get_contract_address_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::get_contract_address_sc, tag)
		{
		}
		mrpc_get_contract_address_sc() : RpcPacket(mpe_rpc_cmd::get_contract_address_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &contract_address);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
