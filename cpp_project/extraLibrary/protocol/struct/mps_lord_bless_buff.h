#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_lord_bless_buff 	// 성주축복버프 정보
	{
	public:
		int32_t id{};	// 버프id
	public:
		int32_t end_time{};	// 종료날짜시간
	public:
		int32_t use_count{};	// 축복버프사용횟수
	public:
		mpe_siege_castle_type castle_type{};	// 성타입

	public:
		mps_lord_bless_buff()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &end_time);
			protocol::SerializeType(pBuffer, &use_count);
			protocol::SerializeEnum(pBuffer, &castle_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
