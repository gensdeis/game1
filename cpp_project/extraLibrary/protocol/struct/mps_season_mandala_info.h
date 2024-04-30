#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_season_mandala_info 	// 시즌 만다라 시즌 정보
	{
	public:
		int32_t id{};	// 시즌 아이디
	public:
		int32_t start_date{};	// 시즌 시작 날짜
	public:
		int32_t end_date{};	// 시즌 종료 날짜
	public:
		mpe_season_mandala_state state{};	// 시즌 상태

	public:
		mps_season_mandala_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &start_date);
			protocol::SerializeType(pBuffer, &end_date);
			protocol::SerializeEnum(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
