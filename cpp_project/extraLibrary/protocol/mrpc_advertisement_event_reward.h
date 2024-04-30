#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_advertisement_event_reward_cs : public RpcPacket 
	{

	public:
		mrpc_advertisement_event_reward_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::advertisement_event_reward_cs, tag)
		{
		}
		mrpc_advertisement_event_reward_cs() : RpcPacket(mpe_rpc_cmd::advertisement_event_reward_cs)
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

	class mrpc_advertisement_event_reward_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};

	public:
		mrpc_advertisement_event_reward_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::advertisement_event_reward_sc, tag)
		{
		}
		mrpc_advertisement_event_reward_sc() : RpcPacket(mpe_rpc_cmd::advertisement_event_reward_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
