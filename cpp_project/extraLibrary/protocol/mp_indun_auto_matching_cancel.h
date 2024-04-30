#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_indun_auto_matching_cancel_cs : public BasePacket 	// // 인던 자동 매칭 취소 알림 용
	{

	public:
		mp_indun_auto_matching_cancel_cs() : BasePacket(mpe_cmd::indun_auto_matching_cancel_cs)
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

	class mp_indun_auto_matching_cancel_sc : public BasePacket 	// // 인던 자동 매칭 취소 알림 용
	{
	public:
		std::string nickname{};	// // 취소 유저 닉네임

	public:
		mp_indun_auto_matching_cancel_sc() : BasePacket(mpe_cmd::indun_auto_matching_cancel_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &nickname);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
