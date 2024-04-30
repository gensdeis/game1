#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_castle_dungeon_info 
	{
	public:
		mpe_siege_castle_type castle_type{};	// 성 종류
	public:
		int32_t entrance_fee{};	// 입장료
	public:
		int32_t apply_entrance_fee{};	// 적용될입장료
	public:
		int32_t entrance_fee_tax{};	// 누적입장료세금

	public:
		mps_castle_dungeon_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &entrance_fee);
			protocol::SerializeType(pBuffer, &apply_entrance_fee);
			protocol::SerializeType(pBuffer, &entrance_fee_tax);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
