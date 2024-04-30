#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_event_reward_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t event_id{};
	public:
		uint16_t reward_sequence{};
	public:
		bool is_advertisement{};
	public:
		int64_t auid{};

	public:
		mrpc_gate_event_reward_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_event_reward_cs, tag)
		{
		}
		mrpc_gate_event_reward_cs() : RpcPacket(mpe_rpc_cmd::gate_event_reward_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &event_id);
			protocol::SerializeType(pBuffer, &reward_sequence);
			protocol::SerializeType(pBuffer, &is_advertisement);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_event_reward_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t result{};
	public:
		int32_t event_id{};
	public:
		uint16_t reward_sequence{};

	public:
		mrpc_gate_event_reward_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_event_reward_sc, tag)
		{
		}
		mrpc_gate_event_reward_sc() : RpcPacket(mpe_rpc_cmd::gate_event_reward_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &event_id);
			protocol::SerializeType(pBuffer, &reward_sequence);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
