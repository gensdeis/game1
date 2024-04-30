#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_repute_quest 
	{
	public:
		int32_t id{};
	public:
		int32_t index{};

	public:
		mps_repute_quest()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
