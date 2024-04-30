#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_profesion_ranking_info 
	{
	public:
		mpe_ranking_type ranking_type{};
	public:
		int32_t profesion_point{};
	public:
		int32_t profesion_level{};

	public:
		mrpcs_profesion_ranking_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &ranking_type);
			protocol::SerializeType(pBuffer, &profesion_point);
			protocol::SerializeType(pBuffer, &profesion_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
