#pragma once
#include <vector>
#include <string>
#include "mps_item.h"

namespace mir3d
{
	class mps_inventory 
	{
	public:
		int32_t size{};
	public:
		int32_t weight{};
	public:
		std::vector<mps_item> list_item{};

	public:
		mps_inventory()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &size);
			protocol::SerializeType(pBuffer, &weight);
			protocol::SerializeType(pBuffer, &list_item);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
