#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_coupon_use_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		std::string player_key{};
	public:
		int64_t cuid{};
	public:
		mpe_coupon_type coupon_type{};
	public:
		std::string coupon_code{};

	public:
		mrpc_gate_coupon_use_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_coupon_use_cs, tag)
		{
		}
		mrpc_gate_coupon_use_cs() : RpcPacket(mpe_rpc_cmd::gate_coupon_use_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &player_key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &coupon_type);
			protocol::SerializeType(pBuffer, &coupon_code);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_coupon_use_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t result_code{};

	public:
		mrpc_gate_coupon_use_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_coupon_use_sc, tag)
		{
		}
		mrpc_gate_coupon_use_sc() : RpcPacket(mpe_rpc_cmd::gate_coupon_use_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &result_code);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
