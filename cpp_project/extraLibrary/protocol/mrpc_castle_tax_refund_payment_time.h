#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_castle_tax_refund_payment_time_cs : public RpcPacket 	// 성 정보
	{

	public:
		mrpc_castle_tax_refund_payment_time_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_tax_refund_payment_time_cs, tag)
		{
		}
		mrpc_castle_tax_refund_payment_time_cs() : RpcPacket(mpe_rpc_cmd::castle_tax_refund_payment_time_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_castle_tax_refund_payment_time_sc : public RpcPacket 	// 성 정보
	{
	public:
		mpe_siege_castle_type castle_type{};	// 세율 변경 성 type
	public:
		bool refund_payment{};	// 정산중확인

	public:
		mrpc_castle_tax_refund_payment_time_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_tax_refund_payment_time_sc, tag)
		{
		}
		mrpc_castle_tax_refund_payment_time_sc() : RpcPacket(mpe_rpc_cmd::castle_tax_refund_payment_time_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &refund_payment);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
