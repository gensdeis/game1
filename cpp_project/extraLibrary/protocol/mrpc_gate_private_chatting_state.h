#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_private_chatting_state_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		bool is_update{};	// 갱신여부
	public:
		bool disable{};

	public:
		mrpc_gate_private_chatting_state_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_private_chatting_state_cs, tag)
		{
		}
		mrpc_gate_private_chatting_state_cs() : RpcPacket(mpe_rpc_cmd::gate_private_chatting_state_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &is_update);
			protocol::SerializeType(pBuffer, &disable);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_private_chatting_state_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		bool is_update{};
	public:
		bool disable{};	// 거부 상태인지 아닌지

	public:
		mrpc_gate_private_chatting_state_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_private_chatting_state_sc, tag)
		{
		}
		mrpc_gate_private_chatting_state_sc() : RpcPacket(mpe_rpc_cmd::gate_private_chatting_state_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &is_update);
			protocol::SerializeType(pBuffer, &disable);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
