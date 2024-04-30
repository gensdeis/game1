#pragma once
#include <vector>
#include <string>
#include "mps_groupid_info.h"

namespace mir3d
{
	class mps_meridians 
	{
	public:
		int32_t id{};	// 경락 id
	public:
		int32_t level{};	// 경락 level
	public:
		std::vector<mps_groupid_info> list_acupoints{};	// 혈도

	public:
		mps_meridians()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &list_acupoints);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
