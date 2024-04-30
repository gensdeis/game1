#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_game_event 
	{
	public:
		mrpce_game_event event_type{};
	public:
		int32_t event_time{};
	public:
		int32_t flag{};	// "상황에 따라 사용하는 변수 (0 : 끝, 1 : 시작) 등.."

	public:
		mrpcs_game_event()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &event_type);
			protocol::SerializeType(pBuffer, &event_time);
			protocol::SerializeType(pBuffer, &flag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
