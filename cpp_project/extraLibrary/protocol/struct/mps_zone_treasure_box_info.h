#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_zone_treasure_box_info 
	{
	public:
		int64_t owner_uid{};	// contribution_type이 FirstAttacker면 character uid, ServerAttacker면 gid 소유권이 없으면 0
	public:
		uint8_t contribution_type{};	// 몬스터 소유권 타입, table enum의 ItemPriority 값을 따름
	public:
		int32_t keep_time{};	// 필드 보물 상자 유지 남은 시간
	public:
		int32_t limit_time{};	// 필드 보물 상자 소유권 제거 남은 시간
	public:
		int32_t item_id{};

	public:
		mps_zone_treasure_box_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &owner_uid);
			protocol::SerializeType(pBuffer, &contribution_type);
			protocol::SerializeType(pBuffer, &keep_time);
			protocol::SerializeType(pBuffer, &limit_time);
			protocol::SerializeType(pBuffer, &item_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
