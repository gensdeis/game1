#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_server_info.h"

namespace mir3d
{
	class mrpc_gm_channel_add_cs : public RpcPacket 
	{
	public:
		std::vector<mrpcs_server_info> channel_list{};

	public:
		mrpc_gm_channel_add_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_channel_add_cs, tag)
		{
		}
		mrpc_gm_channel_add_cs() : RpcPacket(mpe_rpc_cmd::gm_channel_add_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &channel_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_channel_add_sc : public RpcPacket 
	{

	public:
		mrpc_gm_channel_add_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_channel_add_sc, tag)
		{
		}
		mrpc_gm_channel_add_sc() : RpcPacket(mpe_rpc_cmd::gm_channel_add_sc)
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
