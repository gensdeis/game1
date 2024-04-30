#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_street_stall_info 	// // 개인 노점 정보
	{
	public:
		int64_t suid{};	// // 개인 노점 uid
	public:
		int32_t tid{};	// // MapObjectTable Id
	public:
		int32_t profesion_table_id{};	// // profesionTable Id
	public:
		std::string street_stall_title{};	// // 노점 간판 이름
	public:
		int32_t use_count{};	// // 거래 가능 횟수
	public:
		int64_t reset_time{};
	public:
		int64_t cool_time{};	// // 생성 쿨타임
	public:
		int64_t life_time{};	// // 남은시간
	public:
		int32_t channel_id{};

	public:
		mps_street_stall_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &suid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &profesion_table_id);
			protocol::SerializeType(pBuffer, &street_stall_title);
			protocol::SerializeType(pBuffer, &use_count);
			protocol::SerializeType(pBuffer, &reset_time);
			protocol::SerializeType(pBuffer, &cool_time);
			protocol::SerializeType(pBuffer, &life_time);
			protocol::SerializeType(pBuffer, &channel_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
