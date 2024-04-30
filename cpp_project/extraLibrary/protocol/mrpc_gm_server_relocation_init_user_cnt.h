#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_server_relocation_init_user_cnt_cs : public RpcPacket 
	{
	public:
		int32_t gid{};

	public:
		mrpc_gm_server_relocation_init_user_cnt_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_server_relocation_init_user_cnt_cs, tag)
		{
		}
		mrpc_gm_server_relocation_init_user_cnt_cs() : RpcPacket(mpe_rpc_cmd::gm_server_relocation_init_user_cnt_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_server_relocation_init_user_cnt_sc : public RpcPacket 
	{
	public:
		bool is_success{};

	public:
		mrpc_gm_server_relocation_init_user_cnt_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_server_relocation_init_user_cnt_sc, tag)
		{
		}
		mrpc_gm_server_relocation_init_user_cnt_sc() : RpcPacket(mpe_rpc_cmd::gm_server_relocation_init_user_cnt_sc)
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
