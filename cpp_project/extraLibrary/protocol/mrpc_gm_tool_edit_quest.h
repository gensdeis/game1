#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_tool_edit_quest_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		uint16_t quest_tid{};
	public:
		mpe_quest_state state{};
	public:
		int32_t object_count{};

	public:
		mrpc_gm_tool_edit_quest_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_tool_edit_quest_cs, tag)
		{
		}
		mrpc_gm_tool_edit_quest_cs() : RpcPacket(mpe_rpc_cmd::gm_tool_edit_quest_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &quest_tid);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &object_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_tool_edit_quest_sc : public RpcPacket 
	{

	public:
		mrpc_gm_tool_edit_quest_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_tool_edit_quest_sc, tag)
		{
		}
		mrpc_gm_tool_edit_quest_sc() : RpcPacket(mpe_rpc_cmd::gm_tool_edit_quest_sc)
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
