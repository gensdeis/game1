#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_street_stall_product_info.h"

namespace mir3d
{
	class mp_street_stall_start_cs : public BasePacket 	// // 개인 노점 시작 ( 생성 완료 )
	{
	public:
		std::string street_stall_title{};	// // 개인 노점 간판 이름
	public:
		int32_t profesion_table_id{};	// // 상점 타입에 관한 것
	public:
		std::vector<mps_street_stall_product_info> list_product_info{};	// // 등록 상품 정보

	public:
		mp_street_stall_start_cs() : BasePacket(mpe_cmd::street_stall_start_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &street_stall_title);
			protocol::SerializeType(pBuffer, &profesion_table_id);
			protocol::SerializeType(pBuffer, &list_product_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_street_stall_start_sc : public BasePacket 	// // 개인 노점 시작 ( 생성 완료 )
	{
	public:
		int64_t suid{};
	public:
		int64_t cuid{};	// // owner cuid
	public:
		int32_t map_object_table_id{};	// // map object table id
	public:
		std::string street_stall_title{};
	public:
		int32_t profesion_table_id{};	// // 상점 타입에 관한 것
	public:
		int32_t profesion_grade{};	// // 장인 등급
	public:
		int64_t life_time{};

	public:
		mp_street_stall_start_sc() : BasePacket(mpe_cmd::street_stall_start_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &suid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &map_object_table_id);
			protocol::SerializeType(pBuffer, &street_stall_title);
			protocol::SerializeType(pBuffer, &profesion_table_id);
			protocol::SerializeType(pBuffer, &profesion_grade);
			protocol::SerializeType(pBuffer, &life_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
