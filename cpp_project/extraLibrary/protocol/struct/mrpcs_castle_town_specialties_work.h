#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_castle_town_specialties_work 
	{
	public:
		int32_t town_id{};
	public:
		int64_t guid{};
	public:
		mpe_castle_town_specialties_pos specialties_pos{};
	public:
		int32_t gather_value{};
	public:
		bool is_full{};

	public:
		mrpcs_castle_town_specialties_work()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &town_id);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &specialties_pos);
			protocol::SerializeType(pBuffer, &gather_value);
			protocol::SerializeType(pBuffer, &is_full);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
