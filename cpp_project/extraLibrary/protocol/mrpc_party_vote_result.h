#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_party_vote_result_cs : public RpcPacket 
	{

	public:
		mrpc_party_vote_result_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_vote_result_cs, tag)
		{
		}
		mrpc_party_vote_result_cs() : RpcPacket(mpe_rpc_cmd::party_vote_result_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_vote_result_sc : public RpcPacket 
	{
	public:
		mpe_party_vote vote_type{};
	public:
		int64_t puid{};
	public:
		bool vote_result{};
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		mpe_party_loot loot{};
	public:
		int64_t target_cuid{};
	public:
		int32_t indun_id{};

	public:
		mrpc_party_vote_result_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_vote_result_sc, tag)
		{
		}
		mrpc_party_vote_result_sc() : RpcPacket(mpe_rpc_cmd::party_vote_result_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &vote_type);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &vote_result);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeEnum(pBuffer, &loot);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &indun_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
