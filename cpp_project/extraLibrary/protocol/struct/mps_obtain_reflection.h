#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_obtain_reflection 
	{
	public:
		int32_t id{};
	public:
		int32_t keep_value{};
	public:
		bool equip_state{};
	public:
		uint8_t gender{};
	public:
		int32_t add_value{};

	public:
		mps_obtain_reflection()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &keep_value);
			protocol::SerializeType(pBuffer, &equip_state);
			protocol::SerializeType(pBuffer, &gender);
			protocol::SerializeType(pBuffer, &add_value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
