#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_dimension_dungeon_contribution_item 	// 차원비경 기여도랭킹 관련 조각수급량
	{
	public:
		int32_t gid{};	// 서버 아이디
	public:
		int32_t total_amount{};	// 해당 서버의 차원조각 전체수량

	public:
		mrpcs_dimension_dungeon_contribution_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &total_amount);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
