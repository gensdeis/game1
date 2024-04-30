#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_advertisement_event 
	{
	public:
		int32_t event_id{};	// 이벤트 id
	public:
		int32_t count{};	// 보상 횟수
	public:
		int32_t reward_sequence{};	// "이벤트 보상 받아간 일차 (0일차:-1, 1일차:0)"

	public:
		mps_advertisement_event()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &event_id);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &reward_sequence);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
