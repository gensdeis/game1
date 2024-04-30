#pragma once
#include <vector>
#include <string>
#include "mgms_comm_equip.h"

namespace mir3d
{
	class mgms_comm_character 
	{
	public:
		int64_t cuid{};
	public:
		int32_t server_index{};
	public:
		int32_t lv{};
	public:
		std::vector<mgms_comm_equip> equip_list{};
	public:
		int32_t power{};

	public:
		mgms_comm_character()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeType(pBuffer, &lv);
			protocol::SerializeType(pBuffer, &equip_list);
			protocol::SerializeType(pBuffer, &power);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
