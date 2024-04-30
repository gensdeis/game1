#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_connector_rpcinfo_cs : public RpcPacket 
	{
	public:
		int32_t type{};

	public:
		mrpc_connector_rpcinfo_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::connector_rpcinfo_cs, tag)
		{
		}
		mrpc_connector_rpcinfo_cs() : RpcPacket(mpe_rpc_cmd::connector_rpcinfo_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_connector_rpcinfo_sc : public RpcPacket 
	{
	public:
		std::string name{};
	public:
		int32_t gid{};
	public:
		mrpce_server_type type{};
	public:
		int32_t index{};

	public:
		mrpc_connector_rpcinfo_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::connector_rpcinfo_sc, tag)
		{
		}
		mrpc_connector_rpcinfo_sc() : RpcPacket(mpe_rpc_cmd::connector_rpcinfo_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
