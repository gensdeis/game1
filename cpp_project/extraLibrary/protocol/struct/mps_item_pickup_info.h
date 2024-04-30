#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_item_pickup_info 	// 획득아이템정보
	{
	public:
		int32_t index{};	// 가방위치
	public:
		int32_t id{};	// 아이템 id
	public:
		mpe_error error{};	// 결과

	public:
		mps_item_pickup_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeEnum(pBuffer, &error);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
