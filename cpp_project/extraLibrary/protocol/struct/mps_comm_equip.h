#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_comm_equip 
	{
	public:
		int32_t id{};

	public:
		mps_comm_equip()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
