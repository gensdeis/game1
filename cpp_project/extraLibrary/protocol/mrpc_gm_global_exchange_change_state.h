#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_global_exchange_change_state_cs : public RpcPacket 
	{
	public:
		int64_t euid{};
	public:
		mpe_exchange_type exchange_type{};
	public:
		mrpce_exchange_sell_state state{};

	public:
		mrpc_gm_global_exchange_change_state_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_global_exchange_change_state_cs, tag)
		{
		}
		mrpc_gm_global_exchange_change_state_cs() : RpcPacket(mpe_rpc_cmd::gm_global_exchange_change_state_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &euid);
			protocol::SerializeEnum(pBuffer, &exchange_type);
			protocol::SerializeEnum(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_global_exchange_change_state_sc : public RpcPacket 
	{

	public:
		mrpc_gm_global_exchange_change_state_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_global_exchange_change_state_sc, tag)
		{
		}
		mrpc_gm_global_exchange_change_state_sc() : RpcPacket(mpe_rpc_cmd::gm_global_exchange_change_state_sc)
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

}
