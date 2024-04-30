#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_enchant_strone_result 
	{
	public:
		int32_t id{};
	public:
		bool result{};

	public:
		mps_enchant_strone_result()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
