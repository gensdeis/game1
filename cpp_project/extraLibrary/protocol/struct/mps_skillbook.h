#pragma once
#include <vector>
#include <string>
#include "mps_skill.h"
#include "mps_skill.h"

namespace mir3d
{
	class mps_skillbook 
	{
	public:
		std::vector<mps_skill> list_skill{};	// 스킬리스트
	public:
		std::vector<mps_skill> list_passive{};	// 패시브리스트

	public:
		mps_skillbook()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list_skill);
			protocol::SerializeType(pBuffer, &list_passive);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
