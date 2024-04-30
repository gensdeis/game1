#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_rpc_chatting_cs : public RpcPacket 
	{

	public:
		mrpc_gate_rpc_chatting_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_rpc_chatting_cs, tag)
		{
		}
		mrpc_gate_rpc_chatting_cs() : RpcPacket(mpe_rpc_cmd::gate_rpc_chatting_cs)
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

	class mrpc_gate_rpc_chatting_sc : public RpcPacket 
	{
	public:
		mrpce_server_type server_type{};
	public:
		mpe_chatting message_type{};
	public:
		std::vector<int64_t> list{};
	public:
		std::vector<uint8_t> data{};

	public:
		mrpc_gate_rpc_chatting_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_rpc_chatting_sc, tag)
		{
		}
		mrpc_gate_rpc_chatting_sc() : RpcPacket(mpe_rpc_cmd::gate_rpc_chatting_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeEnum(pBuffer, &message_type);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &data);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
