#pragma once
#include <vector>
#include <string>
#include "mps_enchant_stone.h"

namespace mir3d
{
	class mps_mandala_node_info 
	{
	public:
		int32_t node_id{};
	public:
		uint16_t level{};
	public:
		bool state{};
	public:
		int64_t equip_uid{};
	public:
		uint16_t pos{};
	public:
		uint16_t plate_id{};
	private:
		bool flag_stone_info = false;
		mps_enchant_stone stone_info;
		mps_enchant_stone* p_stone_info = nullptr;
	public:
		bool has_stone_info() const
		{
			return flag_stone_info;
		}
		mps_enchant_stone* alloc_stone_info()
		{
			flag_stone_info = true;
			return &stone_info;
		}
		const mps_enchant_stone* get_stone_info() const
		{
			if (true == flag_stone_info)
			{
				if (nullptr == p_stone_info)
				{
					return &stone_info;
				}
				return p_stone_info;
			}
			return nullptr;
		}
		void set_stone_info(mps_enchant_stone* in_stone_info)
		{
			if (nullptr == p_stone_info)
			{
				p_stone_info = in_stone_info;
				flag_stone_info = true;
			}
		}

	public:
		mps_mandala_node_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &node_id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &state);
			protocol::SerializeType(pBuffer, &equip_uid);
			protocol::SerializeType(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &plate_id);
			protocol::SerializeType(pBuffer, &flag_stone_info);
			if (true == flag_stone_info)
			{
				if (nullptr != p_stone_info)
					protocol::SerializeType(pBuffer, p_stone_info);
				else
					protocol::SerializeType(pBuffer, &stone_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
