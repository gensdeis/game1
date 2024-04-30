#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_build_tool_dev_server_group_state.h"

namespace mir3d
{
	class mrpc_build_tool_server_state_cs : public RpcPacket 
	{

	public:
		mrpc_build_tool_server_state_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::build_tool_server_state_cs, tag)
		{
		}
		mrpc_build_tool_server_state_cs() : RpcPacket(mpe_rpc_cmd::build_tool_server_state_cs)
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

	class mrpc_build_tool_server_state_sc : public RpcPacket 
	{
	public:
		std::vector<mrpcs_build_tool_dev_server_group_state> list_server{};

	public:
		mrpc_build_tool_server_state_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::build_tool_server_state_sc, tag)
		{
		}
		mrpc_build_tool_server_state_sc() : RpcPacket(mpe_rpc_cmd::build_tool_server_state_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_server);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
