#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_siege_warfare_battle_result_cs : public RpcPacket 	// 공성전 결과
	{
	public:
		int64_t victory_guild{};	// 승리길드아이디
	public:
		int64_t defeat_guild{};	// 패배길드아이디
	public:
		mrpce_siege_warfare_battle_result result{};	// 공성전 결과
	public:
		mpe_siege_castle_type castle_type{};	// 성 type

	public:
		mrpc_siege_warfare_battle_result_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_battle_result_cs, tag)
		{
		}
		mrpc_siege_warfare_battle_result_cs() : RpcPacket(mpe_rpc_cmd::siege_warfare_battle_result_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &victory_guild);
			protocol::SerializeType(pBuffer, &defeat_guild);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeEnum(pBuffer, &castle_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_siege_warfare_battle_result_sc : public RpcPacket 	// 공성전 결과
	{

	public:
		mrpc_siege_warfare_battle_result_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_battle_result_sc, tag)
		{
		}
		mrpc_siege_warfare_battle_result_sc() : RpcPacket(mpe_rpc_cmd::siege_warfare_battle_result_sc)
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

}
