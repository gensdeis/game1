#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_event_reward_reset_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t last_reward_date{};

	public:
		mrpc_event_reward_reset_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::event_reward_reset_cs, tag)
		{
		}
		mrpc_event_reward_reset_cs() : RpcPacket(mpe_rpc_cmd::event_reward_reset_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &last_reward_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_event_reward_reset_sc : public RpcPacket 
	{

	public:
		mrpc_event_reward_reset_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::event_reward_reset_sc, tag)
		{
		}
		mrpc_event_reward_reset_sc() : RpcPacket(mpe_rpc_cmd::event_reward_reset_sc)
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
