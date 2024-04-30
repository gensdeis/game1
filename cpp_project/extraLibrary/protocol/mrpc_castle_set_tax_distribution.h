#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_castle_set_tax_distribution_cs : public RpcPacket 	// 세금 분배 방식 변경
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		mpe_siege_castle_type castle_type{};	// 세율 변경 성 type
	public:
		mpe_castle_tax_distribution tax_distribution{};	// 분배방식

	public:
		mrpc_castle_set_tax_distribution_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_set_tax_distribution_cs, tag)
		{
		}
		mrpc_castle_set_tax_distribution_cs() : RpcPacket(mpe_rpc_cmd::castle_set_tax_distribution_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeEnum(pBuffer, &tax_distribution);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_castle_set_tax_distribution_sc : public RpcPacket 	// 세금 분배 방식 변경
	{
	public:
		int64_t key{};
	public:
		mpe_siege_castle_type castle_type{};	// 세율 변경 성 type
	public:
		mpe_castle_tax_distribution tax_distribution{};	// 분배방식

	public:
		mrpc_castle_set_tax_distribution_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_set_tax_distribution_sc, tag)
		{
		}
		mrpc_castle_set_tax_distribution_sc() : RpcPacket(mpe_rpc_cmd::castle_set_tax_distribution_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeEnum(pBuffer, &tax_distribution);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
