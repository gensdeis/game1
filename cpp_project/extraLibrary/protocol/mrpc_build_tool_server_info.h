#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_build_tool_server_info.h"
#include "struct/mrpcs_build_tool_branch.h"
#include "struct/mrpcs_build_tool_branch.h"

namespace mir3d
{
	class mrpc_build_tool_server_info_cs : public RpcPacket 
	{

	public:
		mrpc_build_tool_server_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::build_tool_server_info_cs, tag)
		{
		}
		mrpc_build_tool_server_info_cs() : RpcPacket(mpe_rpc_cmd::build_tool_server_info_cs)
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

	class mrpc_build_tool_server_info_sc : public RpcPacket 
	{
	public:
		mrpce_build_tool_type tool_type{};
	public:
		std::vector<mrpcs_build_tool_server_info> list_server{};
	public:
		std::vector<mrpcs_build_tool_branch> list_source_branch{};
	public:
		std::vector<mrpcs_build_tool_branch> list_table_branch{};

	public:
		mrpc_build_tool_server_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::build_tool_server_info_sc, tag)
		{
		}
		mrpc_build_tool_server_info_sc() : RpcPacket(mpe_rpc_cmd::build_tool_server_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &tool_type);
			protocol::SerializeType(pBuffer, &list_server);
			protocol::SerializeType(pBuffer, &list_source_branch);
			protocol::SerializeType(pBuffer, &list_table_branch);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
