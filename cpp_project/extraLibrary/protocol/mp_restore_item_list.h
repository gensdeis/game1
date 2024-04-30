#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_restore_item.h"

namespace mir3d
{
	class mp_restore_item_list_cs : public BasePacket 	// 아이템 복구 리스트 조회 (type별로 호출)
	{
	public:
		mpe_restore_event_type type{};	// 복구 이벤트 타입

	public:
		mp_restore_item_list_cs() : BasePacket(mpe_cmd::restore_item_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_restore_item_list_sc : public BasePacket 	// 아이템 복구 리스트 조회 (type별로 호출)
	{
	public:
		std::vector<mps_restore_item> list{};	// 복구 정보 리스트

	public:
		mp_restore_item_list_sc() : BasePacket(mpe_cmd::restore_item_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
