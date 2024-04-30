#pragma once
#include <vector>
#include <string>
#include "mps_enchant_option.h"
#include "mps_enchant_option.h"
#include "mps_enchant_stone.h"
#include "mps_enchant_option.h"

namespace mir3d
{
	class mps_item_option 
	{
	public:
		int32_t reinforce{};
	public:
		int32_t luck{};
	public:
		std::vector<mps_enchant_option> list_enchant{};
	private:
		bool flag_uniq_option = false;
		mps_enchant_option uniq_option;
		mps_enchant_option* p_uniq_option = nullptr;
	public:
		bool has_uniq_option() const
		{
			return flag_uniq_option;
		}
		mps_enchant_option* alloc_uniq_option()
		{
			flag_uniq_option = true;
			return &uniq_option;
		}
		const mps_enchant_option* get_uniq_option() const
		{
			if (true == flag_uniq_option)
			{
				if (nullptr == p_uniq_option)
				{
					return &uniq_option;
				}
				return p_uniq_option;
			}
			return nullptr;
		}
		void set_uniq_option(mps_enchant_option* in_uniq_option)
		{
			if (nullptr == p_uniq_option)
			{
				p_uniq_option = in_uniq_option;
				flag_uniq_option = true;
			}
		}
	public:
		std::vector<mps_enchant_stone> list_enchant_stone{};
	public:
		std::vector<mps_enchant_option> equip_awaken_unique_option{};	// 각성 장비 고유 옵션
	public:
		std::vector<int32_t> equip_awaken_value{};	// 각성 장비 옵션 증가 정보
	public:
		int32_t equip_awaken_option_confirmed{};	// 각성 장비 옵션 확정 Flag

	public:
		mps_item_option()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &reinforce);
			protocol::SerializeType(pBuffer, &luck);
			protocol::SerializeType(pBuffer, &list_enchant);
			protocol::SerializeType(pBuffer, &flag_uniq_option);
			if (true == flag_uniq_option)
			{
				if (nullptr != p_uniq_option)
					protocol::SerializeType(pBuffer, p_uniq_option);
				else
					protocol::SerializeType(pBuffer, &uniq_option);
			}
			protocol::SerializeType(pBuffer, &list_enchant_stone);
			protocol::SerializeType(pBuffer, &equip_awaken_unique_option);
			protocol::SerializeType(pBuffer, &equip_awaken_value);
			protocol::SerializeType(pBuffer, &equip_awaken_option_confirmed);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
