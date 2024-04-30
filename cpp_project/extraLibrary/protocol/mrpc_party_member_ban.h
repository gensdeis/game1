#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_party_member_ban_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};	// // 탈퇴 요청한 유저 cuid
	public:
		int64_t target_cuid{};	// // 탈퇴 당한 유저 cuid
	public:
		int64_t puid{};

	public:
		mrpc_party_member_ban_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_member_ban_cs, tag)
		{
		}
		mrpc_party_member_ban_cs() : RpcPacket(mpe_rpc_cmd::party_member_ban_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &puid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_member_ban_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t target_cuid{};	// // 탈퇴 당한 유저 cuid
	public:
		int64_t puid{};
	public:
		int64_t cuid{};	// // 탈퇴 요청한 유저 cuid

	public:
		mrpc_party_member_ban_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_member_ban_sc, tag)
		{
		}
		mrpc_party_member_ban_sc() : RpcPacket(mpe_rpc_cmd::party_member_ban_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
