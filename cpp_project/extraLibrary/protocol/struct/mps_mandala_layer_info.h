#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_mandala_layer_info 
	{
	public:
		uint16_t layer_id{};
	public:
		uint16_t plate_id{};
	public:
		uint16_t pos{};

	public:
		mps_mandala_layer_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &layer_id);
			protocol::SerializeType(pBuffer, &plate_id);
			protocol::SerializeType(pBuffer, &pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
