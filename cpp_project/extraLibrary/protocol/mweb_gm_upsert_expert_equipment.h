#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mweb_gm_upsert_expert_equipment_cs : public WebBasePacket 
	{
	public:
		int64_t cuid{};
	public:
		int32_t table_id{};	// "신기테이블id"
	public:
		uint8_t reinforce_lv{};	// "0~59"
	public:
		int32_t is_equip{};	// "-1:수정안함, 0:미착용, 1:착용"
	public:
		int64_t stone1{};	// "-1:수정안함, 0<용령석 iuid, 0:미착용"
	public:
		int64_t stone2{};	// "-1:수정안함, 0<용령석 iuid, 0:미착용"
	public:
		int64_t stone3{};	// "-1:수정안함, 0<용령석 iuid, 0:미착용"

	public:
		mweb_gm_upsert_expert_equipment_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &reinforce_lv);
			protocol::SerializeType(pBuffer, &is_equip);
			protocol::SerializeType(pBuffer, &stone1);
			protocol::SerializeType(pBuffer, &stone2);
			protocol::SerializeType(pBuffer, &stone3);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_gm_upsert_expert_equipment_sc : public WebBasePacket 
	{
	public:
		mpe_error result{};	// 응답 결과

	public:
		mweb_gm_upsert_expert_equipment_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
