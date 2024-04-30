#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_party_vote_request_cs : public BasePacket 
	{
	public:
		int64_t puid{};
	public:
		mpe_party_vote vote{};
	public:
		int64_t cuid{};
	public:
		int64_t target_cuid{};
	public:
		int32_t indun_id{};
	public:
		mpe_party_loot loot{};

	public:
		mp_party_vote_request_cs() : BasePacket(mpe_cmd::party_vote_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeEnum(pBuffer, &vote);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &indun_id);
			protocol::SerializeEnum(pBuffer, &loot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_party_vote_request_sc : public BasePacket 
	{
	public:
		mpe_party_vote vote{};
	public:
		int64_t cuid{};
	public:
		int64_t target_cuid{};
	public:
		std::string nickname{};
	public:
		int32_t indun_id{};
	public:
		mpe_party_loot loot{};

	public:
		mp_party_vote_request_sc() : BasePacket(mpe_cmd::party_vote_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &vote);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &indun_id);
			protocol::SerializeEnum(pBuffer, &loot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
