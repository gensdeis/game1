#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_party_vote_request_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t puid{};
	public:
		mpe_party_vote vote_type{};
	public:
		int64_t cuid{};
	public:
		int64_t target_cuid{};
	public:
		int32_t indun_id{};
	public:
		mpe_party_loot loot{};

	public:
		mrpc_party_vote_request_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_vote_request_cs, tag)
		{
		}
		mrpc_party_vote_request_cs() : RpcPacket(mpe_rpc_cmd::party_vote_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeEnum(pBuffer, &vote_type);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &indun_id);
			protocol::SerializeEnum(pBuffer, &loot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_vote_request_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		mpe_party_vote vote_type{};
	public:
		int64_t puid{};
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
		mrpc_party_vote_request_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_vote_request_sc, tag)
		{
		}
		mrpc_party_vote_request_sc() : RpcPacket(mpe_rpc_cmd::party_vote_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &vote_type);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &indun_id);
			protocol::SerializeEnum(pBuffer, &loot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
