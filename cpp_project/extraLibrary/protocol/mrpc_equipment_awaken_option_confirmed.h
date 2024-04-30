#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_equipment_awaken_option_confirmed_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t iuid{};
	public:
		int32_t option_confirmed{};

	public:
		mrpc_equipment_awaken_option_confirmed_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::equipment_awaken_option_confirmed_cs, tag)
		{
		}
		mrpc_equipment_awaken_option_confirmed_cs() : RpcPacket(mpe_rpc_cmd::equipment_awaken_option_confirmed_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &option_confirmed);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_equipment_awaken_option_confirmed_sc : public RpcPacket 
	{

	public:
		mrpc_equipment_awaken_option_confirmed_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::equipment_awaken_option_confirmed_sc, tag)
		{
		}
		mrpc_equipment_awaken_option_confirmed_sc() : RpcPacket(mpe_rpc_cmd::equipment_awaken_option_confirmed_sc)
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
