#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_adult_certification 
	{
	public:
		mpe_adult_grade grade{};
	public:
		int32_t play_time{};

	public:
		mrpcs_adult_certification()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &grade);
			protocol::SerializeType(pBuffer, &play_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
