#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_dimension_dungeon_contribution 	// 차원비경 기여도랭킹
	{
	public:
		int32_t gid{};	// 서버 아이디
	public:
		int32_t amount{};	// 차원조각 수량
	public:
		int32_t rank{};	// 기여도랭킹
	public:
		int32_t reset_date{};	// 기여도랭킹 리셋시간

	public:
		mrpcs_dimension_dungeon_contribution()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &amount);
			protocol::SerializeType(pBuffer, &rank);
			protocol::SerializeType(pBuffer, &reset_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
