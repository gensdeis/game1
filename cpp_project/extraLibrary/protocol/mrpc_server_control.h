#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_server_control_cs : public RpcPacket 
	{
	public:
		mrpce_server_type server_type{};
	public:
		mrpce_server_control_type control_type{};

	public:
		mrpc_server_control_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_control_cs, tag)
		{
		}
		mrpc_server_control_cs() : RpcPacket(mpe_rpc_cmd::server_control_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeEnum(pBuffer, &control_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_server_control_sc : public RpcPacket 
	{
	public:
		mpe_error result{};

	public:
		mrpc_server_control_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_control_sc, tag)
		{
		}
		mrpc_server_control_sc() : RpcPacket(mpe_rpc_cmd::server_control_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
