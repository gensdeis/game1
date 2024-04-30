#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_party_leave_by_invite_accept_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t old_puid{};
	public:
		int64_t new_puid{};

	public:
		mrpc_party_leave_by_invite_accept_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_leave_by_invite_accept_cs, tag)
		{
		}
		mrpc_party_leave_by_invite_accept_cs() : RpcPacket(mpe_rpc_cmd::party_leave_by_invite_accept_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &old_puid);
			protocol::SerializeType(pBuffer, &new_puid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_leave_by_invite_accept_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t old_puid{};
	public:
		int64_t new_puid{};

	public:
		mrpc_party_leave_by_invite_accept_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_leave_by_invite_accept_sc, tag)
		{
		}
		mrpc_party_leave_by_invite_accept_sc() : RpcPacket(mpe_rpc_cmd::party_leave_by_invite_accept_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &old_puid);
			protocol::SerializeType(pBuffer, &new_puid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
