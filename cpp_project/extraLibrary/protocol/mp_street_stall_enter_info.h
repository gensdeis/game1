#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_street_stall_product_info.h"
#include "struct/mps_street_stall_owner_stat.h"
#include "struct/mps_street_stall_fees.h"
#include "struct/mps_street_stall_log.h"

namespace mir3d
{
	class mp_street_stall_enter_info_cs : public BasePacket 	// // 유인상점 시작시 보내주는 노점 정보
	{

	public:
		mp_street_stall_enter_info_cs() : BasePacket(mpe_cmd::street_stall_enter_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_street_stall_enter_info_sc : public BasePacket 	// // 유인상점 시작시 보내주는 노점 정보
	{
	public:
		std::vector<mps_street_stall_product_info> list_product_info{};	// // 등록 상품 정보
	public:
		std::vector<mps_street_stall_owner_stat> owner_stat{};
	public:
		std::vector<mps_street_stall_fees> total_fees{};
	public:
		int32_t use_count{};
	public:
		std::vector<mps_street_stall_log> log{};

	public:
		mp_street_stall_enter_info_sc() : BasePacket(mpe_cmd::street_stall_enter_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_product_info);
			protocol::SerializeType(pBuffer, &owner_stat);
			protocol::SerializeType(pBuffer, &total_fees);
			protocol::SerializeType(pBuffer, &use_count);
			protocol::SerializeType(pBuffer, &log);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
