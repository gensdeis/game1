#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_character_ranking_info 
	{
	public:
		mpe_ranking_type ranking_type{};
	public:
		int64_t score{};
	public:
		int32_t current_rank{};
	public:
		int32_t max_power{};
	public:
		int32_t stored_pk_point{};
	public:
		int64_t stored_exp{};
	public:
		int32_t stored_force_exp{};
	public:
		int32_t reg_time{};

	public:
		mrpcs_character_ranking_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &ranking_type);
			protocol::SerializeType(pBuffer, &score);
			protocol::SerializeType(pBuffer, &current_rank);
			protocol::SerializeType(pBuffer, &max_power);
			protocol::SerializeType(pBuffer, &stored_pk_point);
			protocol::SerializeType(pBuffer, &stored_exp);
			protocol::SerializeType(pBuffer, &stored_force_exp);
			protocol::SerializeType(pBuffer, &reg_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
