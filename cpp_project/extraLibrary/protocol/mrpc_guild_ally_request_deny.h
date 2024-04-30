#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_ally_request_deny_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};	// "거절한캐릭터 cuid"
	public:
		int64_t my_guid{};	// 내 문파 UID
	public:
		int64_t target_guid{};	// 동맹 요청 문파 UID

	public:
		mrpc_guild_ally_request_deny_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_ally_request_deny_cs, tag)
		{
		}
		mrpc_guild_ally_request_deny_cs() : RpcPacket(mpe_rpc_cmd::guild_ally_request_deny_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &my_guid);
			protocol::SerializeType(pBuffer, &target_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_ally_request_deny_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t deny_guid{};	// 동맹거절한 guid

	public:
		mrpc_guild_ally_request_deny_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_ally_request_deny_sc, tag)
		{
		}
		mrpc_guild_ally_request_deny_sc() : RpcPacket(mpe_rpc_cmd::guild_ally_request_deny_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &deny_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
