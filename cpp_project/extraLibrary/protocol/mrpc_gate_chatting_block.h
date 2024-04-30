#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_chatting_block_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		bool is_block{};	// 차단 or 해제

	public:
		mrpc_gate_chatting_block_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_chatting_block_cs, tag)
		{
		}
		mrpc_gate_chatting_block_cs() : RpcPacket(mpe_rpc_cmd::gate_chatting_block_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &is_block);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_chatting_block_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		mpe_error result{};
	public:
		bool is_block{};	// 차단 or 해제
	public:
		std::string nickname{};

	public:
		mrpc_gate_chatting_block_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_chatting_block_sc, tag)
		{
		}
		mrpc_gate_chatting_block_sc() : RpcPacket(mpe_rpc_cmd::gate_chatting_block_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &is_block);
			protocol::SerializeType(pBuffer, &nickname);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
