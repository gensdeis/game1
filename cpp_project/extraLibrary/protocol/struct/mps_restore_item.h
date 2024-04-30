#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_restore_item 	// 신룡의축복 아이템 강화 실패 정보
	{
	public:
		int64_t ruid{};	// uid
	public:
		mpe_restore_event_type type{};	// 타입
	public:
		int32_t item_id{};	// 아이템 id
	public:
		int32_t reinforce{};	// 강화 수치
	public:
		uint8_t restore{};	// 복구 여부 (1일경우 복구됨)
	public:
		int32_t update_time{};	// 실패 시간 (클라사용x)

	public:
		mps_restore_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &ruid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &item_id);
			protocol::SerializeType(pBuffer, &reinforce);
			protocol::SerializeType(pBuffer, &restore);
			protocol::SerializeType(pBuffer, &update_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
