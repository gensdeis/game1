#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_blood_dedicate_status_subinfo 	// 봉혈 현황 UI 부가정보
	{
	public:
		int32_t id{};
	public:
		int32_t shop_group_id{};

	public:
		mrpcs_blood_dedicate_status_subinfo()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &shop_group_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
