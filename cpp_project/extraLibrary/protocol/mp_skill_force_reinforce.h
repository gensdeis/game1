#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_update_goods.h"
#include "struct/mps_item_count_update.h"

namespace mir3d
{
	class mp_skill_force_reinforce_cs : public BasePacket 
	{
	public:
		uint8_t page_index{};
	public:
		uint8_t skill_lv{};

	public:
		mp_skill_force_reinforce_cs() : BasePacket(mpe_cmd::skill_force_reinforce_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &page_index);
			protocol::SerializeType(pBuffer, &skill_lv);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_skill_force_reinforce_sc : public BasePacket 
	{
	public:
		uint8_t page_index{};
	public:
		uint8_t skill_lv{};
	public:
		mpe_reinforce_result result{};
	private:
		bool flag_update_goods = false;
		mps_update_goods update_goods;	// //변경된재화
		mps_update_goods* p_update_goods = nullptr;
	public:
		bool has_update_goods() const
		{
			return flag_update_goods;
		}
		mps_update_goods* alloc_update_goods()
		{
			flag_update_goods = true;
			return &update_goods;
		}
		const mps_update_goods* get_update_goods() const
		{
			if (true == flag_update_goods)
			{
				if (nullptr == p_update_goods)
				{
					return &update_goods;
				}
				return p_update_goods;
			}
			return nullptr;
		}
		void set_update_goods(mps_update_goods* in_update_goods)
		{
			if (nullptr == p_update_goods)
			{
				p_update_goods = in_update_goods;
				flag_update_goods = true;
			}
		}
	public:
		std::vector<mps_item_count_update> item_info{};

	public:
		mp_skill_force_reinforce_sc() : BasePacket(mpe_cmd::skill_force_reinforce_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &page_index);
			protocol::SerializeType(pBuffer, &skill_lv);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &flag_update_goods);
			if (true == flag_update_goods)
			{
				if (nullptr != p_update_goods)
					protocol::SerializeType(pBuffer, p_update_goods);
				else
					protocol::SerializeType(pBuffer, &update_goods);
			}
			protocol::SerializeType(pBuffer, &item_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
