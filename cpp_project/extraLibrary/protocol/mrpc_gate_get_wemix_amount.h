#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_get_wemix_amount_cs : public RpcPacket 	// 스왑 토큰에 위믹스 달러 수량 조회
	{
	public:
		int64_t key{};
	public:
		mpe_token_type token_type{};	// 위믹스달러로 교환할 토큰
	public:
		std::string total_price{};

	public:
		mrpc_gate_get_wemix_amount_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_get_wemix_amount_cs, tag)
		{
		}
		mrpc_gate_get_wemix_amount_cs() : RpcPacket(mpe_rpc_cmd::gate_get_wemix_amount_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &token_type);
			protocol::SerializeType(pBuffer, &total_price);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_get_wemix_amount_sc : public RpcPacket 	// 스왑 토큰에 위믹스 달러 수량 조회
	{
	public:
		int64_t key{};
	public:
		int32_t result{};
	public:
		std::string swap_amount{};
	public:
		mpe_token_type token_type{};	// 위믹스달러로 교환할 토큰

	public:
		mrpc_gate_get_wemix_amount_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_get_wemix_amount_sc, tag)
		{
		}
		mrpc_gate_get_wemix_amount_sc() : RpcPacket(mpe_rpc_cmd::gate_get_wemix_amount_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &swap_amount);
			protocol::SerializeEnum(pBuffer, &token_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
