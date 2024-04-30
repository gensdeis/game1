#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_subscription_info 	// 캐릭터 구독서비스 정보
	{
	public:
		int32_t subscription_id{};	// 구독서비스 아이디
	public:
		uint8_t subscription_type{};	// 구독서비스 타입(월정액,기간적용상품)
	public:
		int32_t subscription_time{};	// 구독서비스 종료날짜

	public:
		mps_subscription_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &subscription_id);
			protocol::SerializeType(pBuffer, &subscription_type);
			protocol::SerializeType(pBuffer, &subscription_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
