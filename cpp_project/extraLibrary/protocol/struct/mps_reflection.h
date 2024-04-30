#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_reflection 
	{
	public:
		int32_t id{};
	public:
		uint8_t gender{};	// table::gender_type
	public:
		int32_t keep_value{};
	public:
		bool equip_state{};

	public:
		mps_reflection()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &gender);
			protocol::SerializeType(pBuffer, &keep_value);
			protocol::SerializeType(pBuffer, &equip_state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
