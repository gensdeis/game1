#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_vehicle 
	{
	public:
		int32_t tid{};
	public:
		int32_t level{};
	public:
		int32_t exp{};
	public:
		int32_t satiety{};	// 현재 포만감
	public:
		int64_t end_date{};	// 만료일 0 일 경우 무제한
	public:
		std::vector<int64_t> equip_uid{};	// 착용 장비

	public:
		mps_vehicle()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &exp);
			protocol::SerializeType(pBuffer, &satiety);
			protocol::SerializeType(pBuffer, &end_date);
			protocol::SerializeType(pBuffer, &equip_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
