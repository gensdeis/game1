#pragma once
#include <vector>
#include <string>
#include "mps_comm_equip_list.h"

namespace mir3d
{
	class mps_comm_character 
	{
	public:
		int64_t cuid{};
	public:
		int32_t server_index{};
	public:
		int32_t lv{};
	private:
		bool flag_equip_list = false;
		mps_comm_equip_list equip_list;
		mps_comm_equip_list* p_equip_list = nullptr;
	public:
		bool has_equip_list() const
		{
			return flag_equip_list;
		}
		mps_comm_equip_list* alloc_equip_list()
		{
			flag_equip_list = true;
			return &equip_list;
		}
		const mps_comm_equip_list* get_equip_list() const
		{
			if (true == flag_equip_list)
			{
				if (nullptr == p_equip_list)
				{
					return &equip_list;
				}
				return p_equip_list;
			}
			return nullptr;
		}
		void set_equip_list(mps_comm_equip_list* in_equip_list)
		{
			if (nullptr == p_equip_list)
			{
				p_equip_list = in_equip_list;
				flag_equip_list = true;
			}
		}
	public:
		int32_t power{};

	public:
		mps_comm_character()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeType(pBuffer, &lv);
			protocol::SerializeType(pBuffer, &flag_equip_list);
			if (true == flag_equip_list)
			{
				if (nullptr != p_equip_list)
					protocol::SerializeType(pBuffer, p_equip_list);
				else
					protocol::SerializeType(pBuffer, &equip_list);
			}
			protocol::SerializeType(pBuffer, &power);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
