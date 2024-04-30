#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_redis_rpcinfo_list.h"

namespace mir3d
{
	class mrpc_websocket_update_gmserver_manage_info_cs : public RpcPacket 
	{
	public:
		std::string access_token{};

	public:
		mrpc_websocket_update_gmserver_manage_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::websocket_update_gmserver_manage_info_cs, tag)
		{
		}
		mrpc_websocket_update_gmserver_manage_info_cs() : RpcPacket(mpe_rpc_cmd::websocket_update_gmserver_manage_info_cs)
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

	class mrpc_websocket_update_gmserver_manage_info_sc : public RpcPacket 
	{
	public:
		std::string access_token{};
	public:
		int32_t gid{};
	public:
		std::vector<mrpcs_redis_rpcinfo_list> list_rpcinfo{};

	public:
		mrpc_websocket_update_gmserver_manage_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::websocket_update_gmserver_manage_info_sc, tag)
		{
		}
		mrpc_websocket_update_gmserver_manage_info_sc() : RpcPacket(mpe_rpc_cmd::websocket_update_gmserver_manage_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &list_rpcinfo);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
