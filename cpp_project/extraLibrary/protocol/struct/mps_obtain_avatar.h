#pragma once
#include <vector>
#include <string>
#include "mps_skill.h"

namespace mir3d
{
	class mps_obtain_avatar 
	{
	public:
		int32_t avatar_id{};
	public:
		int32_t keep_value{};
	public:
		mpe_avatar_pos pos{};
	public:
		std::vector<mps_skill> list_skill{};
	public:
		int32_t add_count{};

	public:
		mps_obtain_avatar()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &avatar_id);
			protocol::SerializeType(pBuffer, &keep_value);
			protocol::SerializeEnum(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &list_skill);
			protocol::SerializeType(pBuffer, &add_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
