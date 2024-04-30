#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_character_power_cs : public RpcPacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t power{};

	public:
		mrpc_character_power_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_power_cs, tag)
		{
		}
		mrpc_character_power_cs() : RpcPacket(mpe_rpc_cmd::character_power_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &power);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_character_power_sc : public RpcPacket 
	{

	public:
		mrpc_character_power_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::character_power_sc, tag)
		{
		}
		mrpc_character_power_sc() : RpcPacket(mpe_rpc_cmd::character_power_sc)
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
