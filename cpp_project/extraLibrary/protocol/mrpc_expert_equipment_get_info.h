#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_expert_equipment_info.h"

namespace mir3d
{
	class mrpc_expert_equipment_get_info_cs : public RpcPacket 
	{
	public:
		int64_t key{};	// "세션"
	public:
		int64_t cuid{};	// "캐릭터UID"

	public:
		mrpc_expert_equipment_get_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::expert_equipment_get_info_cs, tag)
		{
		}
		mrpc_expert_equipment_get_info_cs() : RpcPacket(mpe_rpc_cmd::expert_equipment_get_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_expert_equipment_get_info_sc : public RpcPacket 
	{
	public:
		int64_t key{};	// "세션"
	public:
		std::vector<mps_expert_equipment_info> expert_equipment_list{};	// "보유신기목록"

	public:
		mrpc_expert_equipment_get_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::expert_equipment_get_info_sc, tag)
		{
		}
		mrpc_expert_equipment_get_info_sc() : RpcPacket(mpe_rpc_cmd::expert_equipment_get_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &expert_equipment_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
