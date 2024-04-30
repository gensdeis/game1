#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mgms_patch_target_group 
	{
	public:
		int32_t gid{};
	public:
		std::vector<int32_t> list_observer_index{};

	public:
		mgms_patch_target_group()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &list_observer_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
