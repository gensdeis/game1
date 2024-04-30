#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_mandala_layer_rotate 
	{
	public:
		uint16_t layer_id{};
	public:
		int32_t rotate_count{};

	public:
		mps_mandala_layer_rotate()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &layer_id);
			protocol::SerializeType(pBuffer, &rotate_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
