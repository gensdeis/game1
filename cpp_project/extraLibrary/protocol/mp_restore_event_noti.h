#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_restore_noti.h"

namespace mir3d
{
	class mp_restore_event_noti_cs : public BasePacket 	// 신룡의축복 noti
	{

	public:
		mp_restore_event_noti_cs() : BasePacket(mpe_cmd::restore_event_noti_cs)
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

	class mp_restore_event_noti_sc : public BasePacket 	// 신룡의축복 noti
	{
	public:
		std::vector<mps_restore_noti> noti_list{};	// 알림 정보

	public:
		mp_restore_event_noti_sc() : BasePacket(mpe_cmd::restore_event_noti_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &noti_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
