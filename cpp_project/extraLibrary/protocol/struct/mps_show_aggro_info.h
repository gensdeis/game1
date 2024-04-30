#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_show_aggro_info 
	{
	public:
		int64_t uid{};
	public:
		float aggro{};

	public:
		mps_show_aggro_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &aggro);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
