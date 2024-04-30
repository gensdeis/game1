#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_darksteel_storage_create 
	{
	public:
		int64_t occupationwar_uid{};
	public:
		mpe_occupationwar_map_type map_type{};
	public:
		int64_t guid{};

	public:
		mrpcs_darksteel_storage_create()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &occupationwar_uid);
			protocol::SerializeEnum(pBuffer, &map_type);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
