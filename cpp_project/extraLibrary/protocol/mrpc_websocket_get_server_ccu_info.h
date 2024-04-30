#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_server_channel_ccu_info.h"

namespace mir3d
{
	class mrpc_websocket_get_server_ccu_info_cs : public RpcPacket 
	{
	public:
		std::string access_token{};

	public:
		mrpc_websocket_get_server_ccu_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::websocket_get_server_ccu_info_cs, tag)
		{
		}
		mrpc_websocket_get_server_ccu_info_cs() : RpcPacket(mpe_rpc_cmd::websocket_get_server_ccu_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_websocket_get_server_ccu_info_sc : public RpcPacket 
	{
	public:
		int32_t count{};
	public:
		int32_t index{};
	public:
		std::vector<mrpcs_server_channel_ccu_info> list{};

	public:
		mrpc_websocket_get_server_ccu_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::websocket_get_server_ccu_info_sc, tag)
		{
		}
		mrpc_websocket_get_server_ccu_info_sc() : RpcPacket(mpe_rpc_cmd::websocket_get_server_ccu_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
