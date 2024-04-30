#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_indun_alert_skip_cs : public BasePacket 
	{

	public:
		mp_indun_alert_skip_cs() : BasePacket(mpe_cmd::indun_alert_skip_cs)
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

	class mp_indun_alert_skip_sc : public BasePacket 
	{
	public:
		uint16_t skip_count{};	// 인원수
	public:
		bool jump_over{};	// 건너뛰기

	public:
		mp_indun_alert_skip_sc() : BasePacket(mpe_cmd::indun_alert_skip_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &skip_count);
			protocol::SerializeType(pBuffer, &jump_over);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
