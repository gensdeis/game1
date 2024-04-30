#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_party_member_ban_cs : public BasePacket 
	{
	public:
		int64_t cuid{};

	public:
		mp_party_member_ban_cs() : BasePacket(mpe_cmd::party_member_ban_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_party_member_ban_sc : public BasePacket 
	{
	public:
		int64_t cuid{};	// // 투표 개설자 (파티장추방 시 해당 cuid 가 파티장)
	public:
		int64_t target_cuid{};	// // 탈퇴 당한자

	public:
		mp_party_member_ban_sc() : BasePacket(mpe_cmd::party_member_ban_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
