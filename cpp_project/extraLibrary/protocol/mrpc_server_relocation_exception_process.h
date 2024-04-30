#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_server_relocation_exception_process_cs : public RpcPacket 	// 서버 이전 오류 발생 시 락업 해제 프로세스
	{
	public:
		int32_t old_gid{};
	public:
		int32_t new_gid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int64_t key{};

	public:
		mrpc_server_relocation_exception_process_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_relocation_exception_process_cs, tag)
		{
		}
		mrpc_server_relocation_exception_process_cs() : RpcPacket(mpe_rpc_cmd::server_relocation_exception_process_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &old_gid);
			protocol::SerializeType(pBuffer, &new_gid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_server_relocation_exception_process_sc : public RpcPacket 	// 서버 이전 오류 발생 시 락업 해제 프로세스
	{
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		bool is_source{};
	public:
		int64_t key{};
	public:
		int32_t old_gid{};
	public:
		int32_t new_gid{};

	public:
		mrpc_server_relocation_exception_process_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_relocation_exception_process_sc, tag)
		{
		}
		mrpc_server_relocation_exception_process_sc() : RpcPacket(mpe_rpc_cmd::server_relocation_exception_process_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &is_source);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &old_gid);
			protocol::SerializeType(pBuffer, &new_gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
