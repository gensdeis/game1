#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_api_server_relocation_rollback_cs : public RpcPacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t old_gid{};
	public:
		int32_t new_gid{};

	public:
		mrpc_api_server_relocation_rollback_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::api_server_relocation_rollback_cs, tag)
		{
		}
		mrpc_api_server_relocation_rollback_cs() : RpcPacket(mpe_rpc_cmd::api_server_relocation_rollback_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &old_gid);
			protocol::SerializeType(pBuffer, &new_gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_api_server_relocation_rollback_sc : public RpcPacket 
	{
	public:
		bool is_success{};

	public:
		mrpc_api_server_relocation_rollback_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::api_server_relocation_rollback_sc, tag)
		{
		}
		mrpc_api_server_relocation_rollback_sc() : RpcPacket(mpe_rpc_cmd::api_server_relocation_rollback_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &is_success);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
