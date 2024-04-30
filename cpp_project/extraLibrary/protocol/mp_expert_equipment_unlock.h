#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_expert_equipment_info.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mp_expert_equipment_unlock_cs : public BasePacket 
	{
	public:
		int32_t expert_equipment_tid{};	// "해금 대상 전직 장비 테이블 id"

	public:
		mp_expert_equipment_unlock_cs() : BasePacket(mpe_cmd::expert_equipment_unlock_cs)
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

	class mp_expert_equipment_unlock_sc : public BasePacket 
	{
	private:
		bool flag_expert_equipment_info = false;
		mps_expert_equipment_info expert_equipment_info;	// "해금된 전직 장비 정보."
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
		std::vector<mps_item_count_update> update_item_counts{};	// "신기 해금 재료 아이템 수량."

	public:
		mp_expert_equipment_unlock_sc() : BasePacket(mpe_cmd::expert_equipment_unlock_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_expert_equipment_info);
			if (true == flag_expert_equipment_info)
			{
				if (nullptr != p_expert_equipment_info)
					protocol::SerializeType(pBuffer, p_expert_equipment_info);
				else
					protocol::SerializeType(pBuffer, &expert_equipment_info);
			}
			protocol::SerializeType(pBuffer, &update_item_counts);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
