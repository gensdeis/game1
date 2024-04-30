#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_object_list 
	{
	public:
		std::vector<int64_t> uid{};

	public:
		mps_object_list()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
