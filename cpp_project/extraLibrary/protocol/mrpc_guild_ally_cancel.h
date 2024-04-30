#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_ally_cancel_cs : public RpcPacket 	// "동맹 해제"
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};	// "해제 요청 캐릭터 cuid"
	public:
		int64_t my_guid{};	// "요청 문파 UID"
	public:
		int64_t target_guid{};	// "대상 문파 UID"

	public:
		mrpc_guild_ally_cancel_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_ally_cancel_cs, tag)
		{
		}
		mrpc_guild_ally_cancel_cs() : RpcPacket(mpe_rpc_cmd::guild_ally_cancel_cs)
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

	class mrpc_guild_ally_cancel_sc : public RpcPacket 	// "동맹 해제"
	{
	public:
		int64_t key{};
	public:
		int64_t target_guid{};	// "동맹 해제된 문파uid"
	public:
		int64_t cancel_time{};	// "동맹해제시간"

	public:
		mrpc_guild_ally_cancel_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_ally_cancel_sc, tag)
		{
		}
		mrpc_guild_ally_cancel_sc() : RpcPacket(mpe_rpc_cmd::guild_ally_cancel_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &target_guid);
			protocol::SerializeType(pBuffer, &cancel_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
