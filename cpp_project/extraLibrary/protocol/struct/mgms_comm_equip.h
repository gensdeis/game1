#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mgms_comm_equip 
	{
	public:
		int32_t tid{};

	public:
		mgms_comm_equip()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
