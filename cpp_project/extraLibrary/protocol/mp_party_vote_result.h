#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_party_vote_result_cs : public BasePacket 
	{

	public:
		mp_party_vote_result_cs() : BasePacket(mpe_cmd::party_vote_result_cs)
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

	class mp_party_vote_result_sc : public BasePacket 
	{
	public:
		mpe_party_vote vote{};
	public:
		bool vote_result{};
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		mpe_party_loot loot{};

	public:
		mp_party_vote_result_sc() : BasePacket(mpe_cmd::party_vote_result_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &vote);
			protocol::SerializeType(pBuffer, &vote_result);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeEnum(pBuffer, &loot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
