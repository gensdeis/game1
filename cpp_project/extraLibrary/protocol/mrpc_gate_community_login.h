#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_community_login_cs : public RpcPacket 	// 채팅 서버 로그인(채팅서버 소켓 연결되고 한번만)
	{
	public:
		int64_t key{};
	public:
		int32_t gid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mrpc_gate_community_login_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_community_login_cs, tag)
		{
		}
		mrpc_gate_community_login_cs() : RpcPacket(mpe_rpc_cmd::gate_community_login_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_community_login_sc : public RpcPacket 	// 채팅 서버 로그인(채팅서버 소켓 연결되고 한번만)
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		mrpce_server_type server_type{};

	public:
		mrpc_gate_community_login_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_community_login_sc, tag)
		{
		}
		mrpc_gate_community_login_sc() : RpcPacket(mpe_rpc_cmd::gate_community_login_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &server_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
