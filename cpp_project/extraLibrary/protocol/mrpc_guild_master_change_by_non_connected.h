#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_member.h"

namespace mir3d
{
	class mrpc_guild_master_change_by_non_connected_cs : public RpcPacket 	// "장기 미접속 문파장 위임 요청"
	{
	public:
		int64_t key{};
	public:
		int64_t request_cuid{};	// "요청 문파원"
	public:
		int64_t guid{};	// "문파uid"

	public:
		mrpc_guild_master_change_by_non_connected_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_master_change_by_non_connected_cs, tag)
		{
		}
		mrpc_guild_master_change_by_non_connected_cs() : RpcPacket(mpe_rpc_cmd::guild_master_change_by_non_connected_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &request_cuid);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_master_change_by_non_connected_sc : public RpcPacket 	// "장기 미접속 문파장 위임 요청"
	{
	public:
		int64_t key{};
	public:
		mpe_guild_member_grade grade{};	// "결과 등급"
	public:
		std::vector<mps_guild_member> list_member{};	// "문파장 변경후 길드 멤버 목록"

	public:
		mrpc_guild_master_change_by_non_connected_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_master_change_by_non_connected_sc, tag)
		{
		}
		mrpc_guild_master_change_by_non_connected_sc() : RpcPacket(mpe_rpc_cmd::guild_master_change_by_non_connected_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &grade);
			protocol::SerializeType(pBuffer, &list_member);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
