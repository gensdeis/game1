#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_expert_equipment_reinforce_cheat_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};	// "캐릭터UID"
	public:
		int32_t table_id{};	// "엑셀테이블의 신기id"
	public:
		uint8_t reinforce_level{};	// "갱신될 강화도"

	public:
		mrpc_expert_equipment_reinforce_cheat_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::expert_equipment_reinforce_cheat_cs, tag)
		{
		}
		mrpc_expert_equipment_reinforce_cheat_cs() : RpcPacket(mpe_rpc_cmd::expert_equipment_reinforce_cheat_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &reinforce_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_expert_equipment_reinforce_cheat_sc : public RpcPacket 
	{

	public:
		mrpc_expert_equipment_reinforce_cheat_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::expert_equipment_reinforce_cheat_sc, tag)
		{
		}
		mrpc_expert_equipment_reinforce_cheat_sc() : RpcPacket(mpe_rpc_cmd::expert_equipment_reinforce_cheat_sc)
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
