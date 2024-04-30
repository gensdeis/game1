#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_trade_info.h"

namespace mir3d
{
	class mrpc_personal_trade_confirm_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t target_key{};
	public:
		std::vector<mps_trade_info> info{};

	public:
		mrpc_personal_trade_confirm_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::personal_trade_confirm_cs, tag)
		{
		}
		mrpc_personal_trade_confirm_cs() : RpcPacket(mpe_rpc_cmd::personal_trade_confirm_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &target_key);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_personal_trade_confirm_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t target_key{};

	public:
		mrpc_personal_trade_confirm_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::personal_trade_confirm_sc, tag)
		{
		}
		mrpc_personal_trade_confirm_sc() : RpcPacket(mpe_rpc_cmd::personal_trade_confirm_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &target_key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
