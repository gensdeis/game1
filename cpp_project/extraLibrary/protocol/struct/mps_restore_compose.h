#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_restore_compose 	// 신룡의축복 합성 실패 정보
	{
	public:
		int64_t ruid{};	// uid
	public:
		mpe_restore_event_type type{};	// 타입
	public:
		uint8_t grade{};	// 합성 등급
	public:
		uint8_t restore{};	// 복구 여부 (1일경우 복구됨)
	public:
		int32_t update_time{};	// 실패 시간 (클라사용x)

	public:
		mps_restore_compose()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &ruid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &grade);
			protocol::SerializeType(pBuffer, &restore);
			protocol::SerializeType(pBuffer, &update_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
