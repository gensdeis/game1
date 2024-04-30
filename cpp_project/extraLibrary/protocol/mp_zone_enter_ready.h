#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_zone_enter_ready_cs : public BasePacket 	// 존 진입 준비
	{

	public:
		mp_zone_enter_ready_cs() : BasePacket(mpe_cmd::zone_enter_ready_cs)
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

	class mp_zone_enter_ready_sc : public BasePacket 	// 존 진입 준비
	{
	public:
		int64_t send_time{};
	public:
		int32_t vehicle_id{};
	public:
		int64_t send_msec{};
	public:
		int32_t indun_end_time{};
	public:
		uint16_t channel_id{};	// 현재 채널 id

	public:
		mp_zone_enter_ready_sc() : BasePacket(mpe_cmd::zone_enter_ready_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &send_time);
			protocol::SerializeType(pBuffer, &vehicle_id);
			protocol::SerializeType(pBuffer, &send_msec);
			protocol::SerializeType(pBuffer, &indun_end_time);
			protocol::SerializeType(pBuffer, &channel_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
