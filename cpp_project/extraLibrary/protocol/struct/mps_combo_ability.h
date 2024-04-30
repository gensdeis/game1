#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_combo_ability 
	{
	public:
		int32_t id{};
	public:
		int32_t value{};

	public:
		mps_combo_ability()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
