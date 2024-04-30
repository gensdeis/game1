#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_blackiron_calc_tax_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};

	public:
		mrpc_blackiron_calc_tax_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blackiron_calc_tax_cs, tag)
		{
		}
		mrpc_blackiron_calc_tax_cs() : RpcPacket(mpe_rpc_cmd::blackiron_calc_tax_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_blackiron_calc_tax_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		mpe_error result{};

	public:
		mrpc_blackiron_calc_tax_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blackiron_calc_tax_sc, tag)
		{
		}
		mrpc_blackiron_calc_tax_sc() : RpcPacket(mpe_rpc_cmd::blackiron_calc_tax_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
