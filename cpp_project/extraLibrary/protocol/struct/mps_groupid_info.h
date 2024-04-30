#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_groupid_info 
	{
	public:
		int32_t gid{};	// table group id
	public:
		int32_t level{};

	public:
		mps_groupid_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
