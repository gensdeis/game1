#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_tool_edit_profession_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		int32_t profession_type{};
	public:
		int32_t level{};
	public:
		int32_t exp{};
	public:
		int32_t grade{};

	public:
		mrpc_gm_tool_edit_profession_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_tool_edit_profession_cs, tag)
		{
		}
		mrpc_gm_tool_edit_profession_cs() : RpcPacket(mpe_rpc_cmd::gm_tool_edit_profession_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &profession_type);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &exp);
			protocol::SerializeType(pBuffer, &grade);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_tool_edit_profession_sc : public RpcPacket 
	{

	public:
		mrpc_gm_tool_edit_profession_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_tool_edit_profession_sc, tag)
		{
		}
		mrpc_gm_tool_edit_profession_sc() : RpcPacket(mpe_rpc_cmd::gm_tool_edit_profession_sc)
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
