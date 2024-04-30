#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_member_base.h"

namespace mir3d
{
	class mp_indun_auto_matching_complete_cs : public BasePacket 	// // 인던 자동 매칭 완료 알림
	{

	public:
		mp_indun_auto_matching_complete_cs() : BasePacket(mpe_cmd::indun_auto_matching_complete_cs)
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

	class mp_indun_auto_matching_complete_sc : public BasePacket 	// // 인던 자동 매칭 완료 알림
	{
	public:
		std::vector<mps_party_member_base> matching_member{};

	public:
		mp_indun_auto_matching_complete_sc() : BasePacket(mpe_cmd::indun_auto_matching_complete_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &matching_member);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
