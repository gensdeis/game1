#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_server_info.h"

namespace mir3d
{
	class mrpc_gm_channel_list_get_cs : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gm_channel_list_get_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_channel_list_get_cs, tag)
		{
		}
		mrpc_gm_channel_list_get_cs() : RpcPacket(mpe_rpc_cmd::gm_channel_list_get_cs)
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

	class mrpc_gm_channel_list_get_sc : public RpcPacket 
	{
	public:
		std::vector<mrpcs_server_info> channel_list{};
	public:
		int64_t key{};

	public:
		mrpc_gm_channel_list_get_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_channel_list_get_sc, tag)
		{
		}
		mrpc_gm_channel_list_get_sc() : RpcPacket(mpe_rpc_cmd::gm_channel_list_get_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &channel_list);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
