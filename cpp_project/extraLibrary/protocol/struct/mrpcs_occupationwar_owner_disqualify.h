#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_occupationwar_owner_disqualify 
	{
	public:
		int64_t guid{};
	public:
		mpe_occupationwar_map_type map_type{};

	public:
		mrpcs_occupationwar_owner_disqualify()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &map_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
