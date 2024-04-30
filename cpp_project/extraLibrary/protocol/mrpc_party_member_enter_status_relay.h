#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_party_member_enter_status_relay_cs : public RpcPacket 	// 파티멤버의 인던 입장 가능 상태 전달
	{
	public:
		int64_t owner_key{};	// 파티장세션
	public:
		int32_t recv_server_gid{};	// 파티장이있는서버의 gid
	public:
		mrpce_server_type recv_server_type{};	// 받을서버의type
	public:
		int32_t recv_server_index{};	// 받을서버의index
	public:
		int64_t puid{};	// 파티uid
	public:
		int64_t member_cuid{};	// 조회할멤버cuid.

	public:
		mrpc_party_member_enter_status_relay_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_member_enter_status_relay_cs, tag)
		{
		}
		mrpc_party_member_enter_status_relay_cs() : RpcPacket(mpe_rpc_cmd::party_member_enter_status_relay_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &owner_key);
			protocol::SerializeType(pBuffer, &recv_server_gid);
			protocol::SerializeEnum(pBuffer, &recv_server_type);
			protocol::SerializeType(pBuffer, &recv_server_index);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &member_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_member_enter_status_relay_sc : public RpcPacket 	// 파티멤버의 인던 입장 가능 상태 전달
	{
	public:
		int64_t owner_key{};	// 파티장세션
	public:
		int64_t puid{};	// 파티uid
	public:
		int64_t member_cuid{};	// 조회된멤버cuid.
	public:
		bool is_ready{};	// 조회된멤버의 입장가능 여부.

	public:
		mrpc_party_member_enter_status_relay_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_member_enter_status_relay_sc, tag)
		{
		}
		mrpc_party_member_enter_status_relay_sc() : RpcPacket(mpe_rpc_cmd::party_member_enter_status_relay_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &owner_key);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &member_cuid);
			protocol::SerializeType(pBuffer, &is_ready);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
