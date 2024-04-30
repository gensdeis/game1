#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_server_relocation_process_global_log_cs : public RpcPacket 	// 서버 이전 프로세스 로그
	{
	public:
		int32_t gid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string msg{};
	public:
		int32_t old_gid{};

	public:
		mrpc_server_relocation_process_global_log_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_relocation_process_global_log_cs, tag)
		{
		}
		mrpc_server_relocation_process_global_log_cs() : RpcPacket(mpe_rpc_cmd::server_relocation_process_global_log_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &msg);
			protocol::SerializeType(pBuffer, &old_gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_server_relocation_process_global_log_sc : public RpcPacket 	// 서버 이전 프로세스 로그
	{
	public:
		int64_t key{};

	public:
		mrpc_server_relocation_process_global_log_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_relocation_process_global_log_sc, tag)
		{
		}
		mrpc_server_relocation_process_global_log_sc() : RpcPacket(mpe_rpc_cmd::server_relocation_process_global_log_sc)
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
