#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_party_vote_reply_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t puid{};
	public:
		int64_t cuid{};
	public:
		bool reply{};

	public:
		mrpc_party_vote_reply_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_vote_reply_cs, tag)
		{
		}
		mrpc_party_vote_reply_cs() : RpcPacket(mpe_rpc_cmd::party_vote_reply_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &reply);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_vote_reply_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t puid{};
	public:
		int64_t cuid{};
	public:
		int64_t target_cuid{};
	public:
		bool reply{};
	public:
		mpe_party_vote vote_type{};

	public:
		mrpc_party_vote_reply_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_vote_reply_sc, tag)
		{
		}
		mrpc_party_vote_reply_sc() : RpcPacket(mpe_rpc_cmd::party_vote_reply_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &reply);
			protocol::SerializeEnum(pBuffer, &vote_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
