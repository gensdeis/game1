#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_subscription_info 	// 캐릭터 구독서비스 정보
	{
	public:
		int32_t id{};	// 구독서비스 아이디
	public:
		uint8_t type{};	// 구독서비스 타입
	public:
		int32_t start_date{};	// 구독서비스 시작날짜
	public:
		int32_t end_date{};	// 구독서비스 종료날짜

	public:
		mrpcs_subscription_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &start_date);
			protocol::SerializeType(pBuffer, &end_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
