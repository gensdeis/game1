#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_tool_remove_quest_info_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		mrpce_gm_remove_quest_info_type flags_remove_target{};

	public:
		mrpc_gm_tool_remove_quest_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_tool_remove_quest_info_cs, tag)
		{
		}
		mrpc_gm_tool_remove_quest_info_cs() : RpcPacket(mpe_rpc_cmd::gm_tool_remove_quest_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeEnum(pBuffer, &flags_remove_target);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_tool_remove_quest_info_sc : public RpcPacket 
	{

	public:
		mrpc_gm_tool_remove_quest_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_tool_remove_quest_info_sc, tag)
		{
		}
		mrpc_gm_tool_remove_quest_info_sc() : RpcPacket(mpe_rpc_cmd::gm_tool_remove_quest_info_sc)
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
