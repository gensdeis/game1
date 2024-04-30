#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_heartbeat_check_cs : public RpcPacket 
	{
	public:
		int64_t uid{};
	public:
		int64_t param{};

	public:
		mrpc_heartbeat_check_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::heartbeat_check_cs, tag)
		{
		}
		mrpc_heartbeat_check_cs() : RpcPacket(mpe_rpc_cmd::heartbeat_check_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &param);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_heartbeat_check_sc : public RpcPacket 
	{
	public:
		int64_t uid{};
	public:
		int64_t param{};

	public:
		mrpc_heartbeat_check_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::heartbeat_check_sc, tag)
		{
		}
		mrpc_heartbeat_check_sc() : RpcPacket(mpe_rpc_cmd::heartbeat_check_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &param);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
