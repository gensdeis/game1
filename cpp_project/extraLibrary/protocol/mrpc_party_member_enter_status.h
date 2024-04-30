#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_party_member_enter_status_cs : public RpcPacket 	// 파티멤버의 인던 입장 가능 상태 요청
	{
	public:
		int64_t owner_key{};	// 파티장세션
	public:
		int32_t recv_server_gid{};	// 파티장이있는서버의 gid
	public:
		mrpce_server_type recv_server_type{};	// 파티장이있는서버의서버타입
	public:
		int32_t recv_server_index{};	// 파티장이있는서버의index
	public:
		int64_t puid{};	// 파티uid
	public:
		std::vector<int64_t> list_cuid{};	// 조회할멤버cuid

	public:
		mrpc_party_member_enter_status_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_member_enter_status_cs, tag)
		{
		}
		mrpc_party_member_enter_status_cs() : RpcPacket(mpe_rpc_cmd::party_member_enter_status_cs)
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
			protocol::SerializeType(pBuffer, &list_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_member_enter_status_sc : public RpcPacket 	// 파티멤버의 인던 입장 가능 상태 요청
	{
	public:
		int64_t owner_key{};	// 파티장세션.실패시에만 전송됨
	public:
		int64_t member_cuid{};	// 조회할멤버cuid.실패시에만 전송됨
	public:
		int64_t puid{};	// 파티uid

	public:
		mrpc_party_member_enter_status_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_member_enter_status_sc, tag)
		{
		}
		mrpc_party_member_enter_status_sc() : RpcPacket(mpe_rpc_cmd::party_member_enter_status_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &owner_key);
			protocol::SerializeType(pBuffer, &member_cuid);
			protocol::SerializeType(pBuffer, &puid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
