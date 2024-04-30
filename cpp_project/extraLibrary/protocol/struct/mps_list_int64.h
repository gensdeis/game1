#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_list_int64 	//  db 등에서 사용되고 있음"
	{
	public:
		std::vector<int64_t> list{};

	public:
		mps_list_int64()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
