#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods_list.h"
#include "struct/mps_item_count_update.h"
#include "struct/mps_expert_equipment_info.h"

namespace mir3d
{
	class mp_expert_equipment_reinforce_cs : public BasePacket 
	{
	public:
		int32_t expert_equipment_tid{};	// "대상 전직 장비 테이블 id"

	public:
		mp_expert_equipment_reinforce_cs() : BasePacket(mpe_cmd::expert_equipment_reinforce_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &expert_equipment_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_expert_equipment_reinforce_sc : public BasePacket 
	{
	private:
		bool flag_good_list = false;
		mps_update_goods_list good_list;	// "갱신된 재화"
		mps_update_goods_list* p_good_list = nullptr;
	public:
		bool has_good_list() const
		{
			return flag_good_list;
		}
		mps_update_goods_list* alloc_good_list()
		{
			flag_good_list = true;
			return &good_list;
		}
		const mps_update_goods_list* get_good_list() const
		{
			if (true == flag_good_list)
			{
				if (nullptr == p_good_list)
				{
					return &good_list;
				}
				return p_good_list;
			}
			return nullptr;
		}
		void set_good_list(mps_update_goods_list* in_good_list)
		{
			if (nullptr == p_good_list)
			{
				p_good_list = in_good_list;
				flag_good_list = true;
			}
		}
	public:
		std::vector<mps_item_count_update> update_item_counts{};	// "차감된 아이템 목록."
	private:
		bool flag_expert_equipment_info = false;
		mps_expert_equipment_info expert_equipment_info;	// "강화 완료된 전직 장비 정보."
		mps_expert_equipment_info* p_expert_equipment_info = nullptr;
	public:
		bool has_expert_equipment_info() const
		{
			return flag_expert_equipment_info;
		}
		mps_expert_equipment_info* alloc_expert_equipment_info()
		{
			flag_expert_equipment_info = true;
			return &expert_equipment_info;
		}
		const mps_expert_equipment_info* get_expert_equipment_info() const
		{
			if (true == flag_expert_equipment_info)
			{
				if (nullptr == p_expert_equipment_info)
				{
					return &expert_equipment_info;
				}
				return p_expert_equipment_info;
			}
			return nullptr;
		}
		void set_expert_equipment_info(mps_expert_equipment_info* in_expert_equipment_info)
		{
			if (nullptr == p_expert_equipment_info)
			{
				p_expert_equipment_info = in_expert_equipment_info;
				flag_expert_equipment_info = true;
			}
		}
	public:
		mpe_upgrade_state result{};	// "강화결과"
	public:
		std::vector<int32_t> list_special_move_slot{};	// "변경된 필살기 슬롯 정보, 필살기 각성이 아니거나 강화에 실패했으면 이전 정보 그대로"

	public:
		mp_expert_equipment_reinforce_sc() : BasePacket(mpe_cmd::expert_equipment_reinforce_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_good_list);
			if (true == flag_good_list)
			{
				if (nullptr != p_good_list)
					protocol::SerializeType(pBuffer, p_good_list);
				else
					protocol::SerializeType(pBuffer, &good_list);
			}
			protocol::SerializeType(pBuffer, &update_item_counts);
			protocol::SerializeType(pBuffer, &flag_expert_equipment_info);
			if (true == flag_expert_equipment_info)
			{
				if (nullptr != p_expert_equipment_info)
					protocol::SerializeType(pBuffer, p_expert_equipment_info);
				else
					protocol::SerializeType(pBuffer, &expert_equipment_info);
			}
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &list_special_move_slot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
