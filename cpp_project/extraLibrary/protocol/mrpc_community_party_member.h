#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_community_party_member_cs : public RpcPacket 
	{

	public:
		mrpc_community_party_member_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_party_member_cs, tag)
		{
		}
		mrpc_community_party_member_cs() : RpcPacket(mpe_rpc_cmd::community_party_member_cs)
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

	class mrpc_community_party_member_sc : public RpcPacket 
	{
	public:
		int64_t puid{};
	public:
		int64_t cuid{};
	public:
		bool flag{};	// true = 멤버등록 / false = 멤버탈퇴

	public:
		mrpc_community_party_member_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_party_member_sc, tag)
		{
		}
		mrpc_community_party_member_sc() : RpcPacket(mpe_rpc_cmd::community_party_member_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &flag);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
