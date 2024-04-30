#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_vehicle_autosave 
	{
	public:
		int32_t tid{};
	public:
		int32_t satiety{};

	public:
		mrpcs_vehicle_autosave()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &satiety);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
