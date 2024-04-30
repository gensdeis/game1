#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_season_mandala_reward_info 	// 시즌 만다라 캐릭터별 보상정보
	{
	public:
		int32_t table_id{};	// 보상 테이블 아이디
	public:
		mpe_season_mandala_reward_receive_type receive_type{};	// 보상수령 타입
	public:
		int32_t receive_date{};	// 보상수령 시간

	public:
		mps_season_mandala_reward_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeEnum(pBuffer, &receive_type);
			protocol::SerializeType(pBuffer, &receive_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
