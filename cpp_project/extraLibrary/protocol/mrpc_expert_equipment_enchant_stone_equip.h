#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_equip_info_list.h"

namespace mir3d
{
	class mrpc_expert_equipment_enchant_stone_equip_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int32_t table_id{};	// "엑셀테이블의 신기id"
	public:
		uint8_t slot_num{};	// "착용슬롯번호"
	public:
		int64_t enchant_stone_iuid{};	// "용령석 item uid"
	private:
		bool flag_equip_info_list = false;
		mps_equip_info_list equip_info_list;	// "갱신되는 용령석 아이템"
		mps_equip_info_list* p_equip_info_list = nullptr;
	public:
		bool has_equip_info_list() const
		{
			return flag_equip_info_list;
		}
		mps_equip_info_list* alloc_equip_info_list()
		{
			flag_equip_info_list = true;
			return &equip_info_list;
		}
		const mps_equip_info_list* get_equip_info_list() const
		{
			if (true == flag_equip_info_list)
			{
				if (nullptr == p_equip_info_list)
				{
					return &equip_info_list;
				}
				return p_equip_info_list;
			}
			return nullptr;
		}
		void set_equip_info_list(mps_equip_info_list* in_equip_info_list)
		{
			if (nullptr == p_equip_info_list)
			{
				p_equip_info_list = in_equip_info_list;
				flag_equip_info_list = true;
			}
		}

	public:
		mrpc_expert_equipment_enchant_stone_equip_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::expert_equipment_enchant_stone_equip_cs, tag)
		{
		}
		mrpc_expert_equipment_enchant_stone_equip_cs() : RpcPacket(mpe_rpc_cmd::expert_equipment_enchant_stone_equip_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &slot_num);
			protocol::SerializeType(pBuffer, &enchant_stone_iuid);
			protocol::SerializeType(pBuffer, &flag_equip_info_list);
			if (true == flag_equip_info_list)
			{
				if (nullptr != p_equip_info_list)
					protocol::SerializeType(pBuffer, p_equip_info_list);
				else
					protocol::SerializeType(pBuffer, &equip_info_list);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_expert_equipment_enchant_stone_equip_sc : public RpcPacket 
	{

	public:
		mrpc_expert_equipment_enchant_stone_equip_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::expert_equipment_enchant_stone_equip_sc, tag)
		{
		}
		mrpc_expert_equipment_enchant_stone_equip_sc() : RpcPacket(mpe_rpc_cmd::expert_equipment_enchant_stone_equip_sc)
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
