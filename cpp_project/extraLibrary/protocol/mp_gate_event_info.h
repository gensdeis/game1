#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_event_info.h"
#include "struct/mps_advertisement_event.h"
#include "struct/mps_restore_noti.h"

namespace mir3d
{
	class mp_gate_event_info_cs : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t auid{};

	public:
		mp_gate_event_info_cs() : BasePacket(mpe_cmd::gate_event_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_event_info_sc : public BasePacket 
	{
	public:
		int32_t result{};
	public:
		std::vector<mps_event_info> info{};
	public:
		int32_t create_time{};
	public:
		int32_t cumulative_connection_time{};
	public:
		std::vector<mps_advertisement_event>  advertisement_event_list{};
	public:
		mpe_account_category account_category{};	// 계정 카테고리(기존,복귀,신규)
	public:
		std::vector<mps_restore_noti> restore_event_noti{};	// 신룡의 축복 알림

	public:
		mp_gate_event_info_sc() : BasePacket(mpe_cmd::gate_event_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &create_time);
			protocol::SerializeType(pBuffer, &cumulative_connection_time);
			protocol::SerializeType(pBuffer, & advertisement_event_list);
			protocol::SerializeEnum(pBuffer, &account_category);
			protocol::SerializeType(pBuffer, &restore_event_noti);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
