#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_coin_recall_cooltime_info 	// 코인 회수 불가능 쿨타임 정보
	{
	public:
		int32_t last_staking_datetime{};	// 마지막 코인 스테이킹 시간
	public:
		int32_t last_unstaking_datetime{};	// 마지막 코인 언스테이킹 시간

	public:
		mrpcs_coin_recall_cooltime_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &last_staking_datetime);
			protocol::SerializeType(pBuffer, &last_unstaking_datetime);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
