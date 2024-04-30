#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_refinery_daily_limit 	// 제련소 일일제한 횟수 정보
	{
	public:
		int64_t auid{};	// 계정 아이디
	public:
		int32_t logdate{};	// 갱신 시간
	public:
		int32_t count{};	// 일일 제한횟수

	public:
		mrpcs_refinery_daily_limit()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &logdate);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
