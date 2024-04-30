#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_blood_dedicate_zone_chatting_cs : public BasePacket 	// 봉혈 성공시 전달되는 지역채팅 메시지
	{

	public:
		mp_blood_dedicate_zone_chatting_cs() : BasePacket(mpe_cmd::blood_dedicate_zone_chatting_cs)
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

	class mp_blood_dedicate_zone_chatting_sc : public BasePacket 	// 봉혈 성공시 전달되는 지역채팅 메시지
	{
	public:
		mpe_error result{};	// 응답 결과(토스트메시지 출력시 사용)

	public:
		mp_blood_dedicate_zone_chatting_sc() : BasePacket(mpe_cmd::blood_dedicate_zone_chatting_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
