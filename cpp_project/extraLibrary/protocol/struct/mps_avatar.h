#pragma once
#include <vector>
#include <string>
#include "mps_skill.h"

namespace mir3d
{
	class mps_avatar 
	{
	public:
		int32_t avatar_id{};
	public:
		int32_t keep_value{};	// 여분 아바타 개수
	public:
		mpe_avatar_pos pos{};	// 슬롯장착위치
	public:
		std::vector<mps_skill> list_skill{};

	public:
		mps_avatar()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &avatar_id);
			protocol::SerializeType(pBuffer, &keep_value);
			protocol::SerializeEnum(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &list_skill);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
