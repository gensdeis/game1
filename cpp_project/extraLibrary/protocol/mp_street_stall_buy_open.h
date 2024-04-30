#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_street_stall_product_info.h"
#include "struct/mps_street_stall_owner_stat.h"

namespace mir3d
{
	class mp_street_stall_buy_open_cs : public BasePacket 	// // 유인상점 시작시 보내주는 노점 정보
	{
	public:
		int64_t suid{};	// // 개인 노점 uid

	public:
		mp_street_stall_buy_open_cs() : BasePacket(mpe_cmd::street_stall_buy_open_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &suid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_street_stall_buy_open_sc : public BasePacket 	// // 유인상점 시작시 보내주는 노점 정보
	{
	public:
		int32_t profesion_level{};	// // 장인 레벨
	public:
		int32_t profesion_grade{};
	public:
		int32_t profesion_table_id{};
	public:
		std::vector<mps_street_stall_product_info> list_product_info{};	// // 등록 상품 정보
	public:
		std::vector<mps_street_stall_owner_stat> owner_stat{};	// // 노점 주인 stat
	public:
		int32_t use_count{};	// // 제작 가능 횟수

	public:
		mp_street_stall_buy_open_sc() : BasePacket(mpe_cmd::street_stall_buy_open_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &profesion_level);
			protocol::SerializeType(pBuffer, &profesion_grade);
			protocol::SerializeType(pBuffer, &profesion_table_id);
			protocol::SerializeType(pBuffer, &list_product_info);
			protocol::SerializeType(pBuffer, &owner_stat);
			protocol::SerializeType(pBuffer, &use_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
