#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_equip_item_info 
	{
	public:
		int32_t id{};
	public:
		int32_t reinforce{};

	public:
		mps_equip_item_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &reinforce);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
