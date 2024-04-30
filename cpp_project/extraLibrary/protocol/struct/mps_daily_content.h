#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_daily_content 
	{
	public:
		int64_t reset_time{};	// "일일컨텐츠초기화시간(초,UTC)"
	public:
		int32_t condition_limit{};	// 일일피로도충전제한량

	public:
		mps_daily_content()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &reset_time);
			protocol::SerializeType(pBuffer, &condition_limit);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
