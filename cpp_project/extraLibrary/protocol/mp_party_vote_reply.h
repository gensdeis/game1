#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_party_vote_reply_cs : public BasePacket 
	{
	public:
		bool reply{};

	public:
		mp_party_vote_reply_cs() : BasePacket(mpe_cmd::party_vote_reply_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &reply);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_party_vote_reply_sc : public BasePacket 
	{
	public:
		bool reply{};
	public:
		int64_t cuid{};	// // 투표 진행한 유저 cuid

	public:
		mp_party_vote_reply_sc() : BasePacket(mpe_cmd::party_vote_reply_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &reply);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
