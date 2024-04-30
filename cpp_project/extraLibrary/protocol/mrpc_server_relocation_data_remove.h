#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_server_relocation_data_remove_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};	// 캐릭터UID
	public:
		int32_t gid{};	// 이동 전 서버 ID
	public:
		int32_t class_type{};	// 캐릭터 tid
	public:
		bool is_move_world{};	// 월드 이동 여부

	public:
		mrpc_server_relocation_data_remove_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_relocation_data_remove_cs, tag)
		{
		}
		mrpc_server_relocation_data_remove_cs() : RpcPacket(mpe_rpc_cmd::server_relocation_data_remove_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &class_type);
			protocol::SerializeType(pBuffer, &is_move_world);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_server_relocation_data_remove_sc : public RpcPacket 
	{

	public:
		mrpc_server_relocation_data_remove_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_relocation_data_remove_sc, tag)
		{
		}
		mrpc_server_relocation_data_remove_sc() : RpcPacket(mpe_rpc_cmd::server_relocation_data_remove_sc)
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

}
