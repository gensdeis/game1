#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_castle_set_tax_rate_cs : public RpcPacket 	// 세율 변경
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
		int32_t tax_rate{};	// 변경 세율

	public:
		mrpc_castle_set_tax_rate_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_set_tax_rate_cs, tag)
		{
		}
		mrpc_castle_set_tax_rate_cs() : RpcPacket(mpe_rpc_cmd::castle_set_tax_rate_cs)
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
			protocol::SerializeType(pBuffer, &tax_rate);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_castle_set_tax_rate_sc : public RpcPacket 	// 세율 변경
	{
	public:
		int64_t key{};
	public:
		mpe_siege_castle_type castle_type{};	// 세율 변경 성 type
	public:
		int32_t tax_rate{};	// 변경 세율
	public:
		int64_t tax_rate_reg_time{};	// 세금변경날짜

	public:
		mrpc_castle_set_tax_rate_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_set_tax_rate_sc, tag)
		{
		}
		mrpc_castle_set_tax_rate_sc() : RpcPacket(mpe_rpc_cmd::castle_set_tax_rate_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &tax_rate);
			protocol::SerializeType(pBuffer, &tax_rate_reg_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
