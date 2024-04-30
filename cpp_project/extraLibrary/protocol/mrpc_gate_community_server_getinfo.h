#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_community_server_getinfo_cs : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gate_community_server_getinfo_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_community_server_getinfo_cs, tag)
		{
		}
		mrpc_gate_community_server_getinfo_cs() : RpcPacket(mpe_rpc_cmd::gate_community_server_getinfo_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_community_server_getinfo_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::string community_ip{};	// 채팅서버 정보
	public:
		uint16_t community_port{};	// 채팅서버 정보

	public:
		mrpc_gate_community_server_getinfo_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_community_server_getinfo_sc, tag)
		{
		}
		mrpc_gate_community_server_getinfo_sc() : RpcPacket(mpe_rpc_cmd::gate_community_server_getinfo_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &community_ip);
			protocol::SerializeType(pBuffer, &community_port);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
