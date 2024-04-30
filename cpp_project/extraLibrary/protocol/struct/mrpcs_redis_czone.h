#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_redis_czone 
	{
	public:
		int32_t server_index{};	// serveridx
	public:
		int64_t zuid{};
	public:
		int32_t zone_id{};
	public:
		mrpce_server_type type{};
	public:
		int32_t user_max{};
	public:
		uint8_t state{};
	public:
		int32_t user_count{};	// 접속 유저수
	public:
		int32_t use_pool{};	// 인던 생성 풀 카운드
	public:
		bool is_create{};	// 인던 미리 생성 여부
	public:
		int32_t update_time{};

	public:
		mrpcs_redis_czone()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeType(pBuffer, &zuid);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &user_max);
			protocol::SerializeType(pBuffer, &state);
			protocol::SerializeType(pBuffer, &user_count);
			protocol::SerializeType(pBuffer, &use_pool);
			protocol::SerializeType(pBuffer, &is_create);
			protocol::SerializeType(pBuffer, &update_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
