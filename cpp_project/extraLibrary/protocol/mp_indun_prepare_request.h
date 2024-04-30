#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_indun_prepare_request_cs : public BasePacket 	// "// 인던 입장 신청 패킷 ( 바로시작
	{
	public:
		int32_t tid{};	// // dungeon constrol table id
	public:
		int32_t party_category{};	// "대상파티카테고리. 자동매칭시 필요"
	public:
		mpe_indun_enter_type type{};	// // 인던 입장 방식 
	public:
		uint8_t require_item_index{};	// "// dungeonControlTable 입장 재화 인덱스 (입장 시 선택한 것, 없으면 0)"
	public:
		std::vector<int32_t> list_item_id{};	// // 소환석 아이템 id 목록

	public:
		mp_indun_prepare_request_cs() : BasePacket(mpe_cmd::indun_prepare_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &party_category);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &require_item_index);
			protocol::SerializeType(pBuffer, &list_item_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_indun_prepare_request_sc : public BasePacket 	// "// 인던 입장 신청 패킷 ( 바로시작
	{
	public:
		int32_t tid{};	// // dungeon constrol table id
	public:
		mpe_indun_enter_type type{};	// // 인던 입장 방식 

	public:
		mp_indun_prepare_request_sc() : BasePacket(mpe_cmd::indun_prepare_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
