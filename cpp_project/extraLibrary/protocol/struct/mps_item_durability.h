#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_item_durability 	// 아이템 내구도 저장
	{
	public:
		int64_t iuid{};
	public:
		uint16_t durability{};

	public:
		mps_item_durability()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &durability);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
