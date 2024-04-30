#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_gm_subscription_info 	// MBPS에 전달할 캐릭터 구독서비스 정보
	{
	public:
		int32_t id{};	// 구독서비스 아이디
	public:
		int32_t name_id{};	// 구독서비스 이름 아이디
	public:
		int32_t end_date{};	// 구독서비스 종료날짜

	public:
		mrpcs_gm_subscription_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &name_id);
			protocol::SerializeType(pBuffer, &end_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
