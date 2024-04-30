#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_dimension_dungeon_cmd_cs : public RpcPacket 
	{
	public:
		mpe_dimension_dungeon_schedule_type schedule_type{};
	public:
		int32_t remain_sec{};	// "pre_open 에만 적용됨."

	public:
		mrpc_gm_dimension_dungeon_cmd_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_dimension_dungeon_cmd_cs, tag)
		{
		}
		mrpc_gm_dimension_dungeon_cmd_cs() : RpcPacket(mpe_rpc_cmd::gm_dimension_dungeon_cmd_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &schedule_type);
			protocol::SerializeType(pBuffer, &remain_sec);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_dimension_dungeon_cmd_sc : public RpcPacket 
	{
	public:
		bool is_success{};

	public:
		mrpc_gm_dimension_dungeon_cmd_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_dimension_dungeon_cmd_sc, tag)
		{
		}
		mrpc_gm_dimension_dungeon_cmd_sc() : RpcPacket(mpe_rpc_cmd::gm_dimension_dungeon_cmd_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &is_success);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
