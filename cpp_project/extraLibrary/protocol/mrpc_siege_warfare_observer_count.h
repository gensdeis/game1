#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_siege_warfare_observer_count_cs : public RpcPacket 	// 공성전 참여 관전자 수 변경
	{
	public:
		mpe_siege_castle_type castle_type{};
	public:
		uint8_t count{};

	public:
		mrpc_siege_warfare_observer_count_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_observer_count_cs, tag)
		{
		}
		mrpc_siege_warfare_observer_count_cs() : RpcPacket(mpe_rpc_cmd::siege_warfare_observer_count_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_siege_warfare_observer_count_sc : public RpcPacket 	// 공성전 참여 관전자 수 변경
	{

	public:
		mrpc_siege_warfare_observer_count_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_observer_count_sc, tag)
		{
		}
		mrpc_siege_warfare_observer_count_sc() : RpcPacket(mpe_rpc_cmd::siege_warfare_observer_count_sc)
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
