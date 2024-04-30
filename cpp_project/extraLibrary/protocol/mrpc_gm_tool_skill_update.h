#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_tool_skill_update_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		int32_t skill_tid{};
	public:
		int32_t level{};
	public:
		int32_t exp{};

	public:
		mrpc_gm_tool_skill_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_tool_skill_update_cs, tag)
		{
		}
		mrpc_gm_tool_skill_update_cs() : RpcPacket(mpe_rpc_cmd::gm_tool_skill_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &skill_tid);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &exp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_tool_skill_update_sc : public RpcPacket 
	{

	public:
		mrpc_gm_tool_skill_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_tool_skill_update_sc, tag)
		{
		}
		mrpc_gm_tool_skill_update_sc() : RpcPacket(mpe_rpc_cmd::gm_tool_skill_update_sc)
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
