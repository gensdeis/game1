#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_build_tool_server_command_cs : public RpcPacket 
	{
	public:
		mrpce_build_tool_command cmd{};
	public:
		mrpce_build_tool_type type{};
	public:
		mrpce_build_tool_type tool_type{};
	public:
		int32_t gid{};
	public:
		int32_t index{};
	public:
		int64_t uid{};
	public:
		int32_t file_size{};
	public:
		int32_t file_current_index{};
	public:
		int32_t file_max_index{};
	public:
		std::vector<uint8_t> data{};

	public:
		mrpc_build_tool_server_command_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::build_tool_server_command_cs, tag)
		{
		}
		mrpc_build_tool_server_command_cs() : RpcPacket(mpe_rpc_cmd::build_tool_server_command_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &cmd);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeEnum(pBuffer, &tool_type);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &file_size);
			protocol::SerializeType(pBuffer, &file_current_index);
			protocol::SerializeType(pBuffer, &file_max_index);
			protocol::SerializeType(pBuffer, &data);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_build_tool_server_command_sc : public RpcPacket 
	{
	public:
		mrpce_build_tool_command cmd{};
	public:
		mrpce_build_tool_type type{};
	public:
		mrpce_build_tool_command_state state{};
	public:
		int32_t gid{};
	public:
		int32_t index{};
	public:
		int64_t uid{};
	public:
		int32_t file_size{};
	public:
		int32_t file_current_index{};
	public:
		int32_t file_max_index{};
	public:
		std::vector<uint8_t> data{};

	public:
		mrpc_build_tool_server_command_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::build_tool_server_command_sc, tag)
		{
		}
		mrpc_build_tool_server_command_sc() : RpcPacket(mpe_rpc_cmd::build_tool_server_command_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &cmd);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &file_size);
			protocol::SerializeType(pBuffer, &file_current_index);
			protocol::SerializeType(pBuffer, &file_max_index);
			protocol::SerializeType(pBuffer, &data);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
