#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_loginserver_duplicate_login_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};

	public:
		mrpc_gate_loginserver_duplicate_login_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_loginserver_duplicate_login_cs, tag)
		{
		}
		mrpc_gate_loginserver_duplicate_login_cs() : RpcPacket(mpe_rpc_cmd::gate_loginserver_duplicate_login_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_loginserver_duplicate_login_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gate_loginserver_duplicate_login_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_loginserver_duplicate_login_sc, tag)
		{
		}
		mrpc_gate_loginserver_duplicate_login_sc() : RpcPacket(mpe_rpc_cmd::gate_loginserver_duplicate_login_sc)
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

}
