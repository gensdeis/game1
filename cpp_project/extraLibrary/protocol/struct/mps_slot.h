#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_slot 
	{
	public:
		int64_t id{};
	public:
		int32_t pos{};

	public:
		mps_slot()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
