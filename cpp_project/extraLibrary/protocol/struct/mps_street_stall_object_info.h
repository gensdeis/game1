#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_street_stall_object_info 	// // 개인 노점 정보
	{
	public:
		int64_t suid{};	// // 개인 노점 uid
	public:
		int64_t owner_cuid{};
	public:
		int32_t tid{};	// // MapObjectTable Id
	public:
		int32_t profesion_table_id{};	// // profesionTable Id
	public:
		int32_t profesion_grade{};	// // 장인 등급
	public:
		std::string street_stall_title{};	// // 노점 간판 이름
	public:
		int32_t npc_info{};	// "// 0 : 유인, 1 : npc 사용 - 추후 npc 아이디(shop 어시스트) 값으로 변경할수 있음"

	public:
		mps_street_stall_object_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &suid);
			protocol::SerializeType(pBuffer, &owner_cuid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &profesion_table_id);
			protocol::SerializeType(pBuffer, &profesion_grade);
			protocol::SerializeType(pBuffer, &street_stall_title);
			protocol::SerializeType(pBuffer, &npc_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
