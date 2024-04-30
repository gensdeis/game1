#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_blackiron_collect_tax_cs : public RpcPacket 
	{
	public:
		uint8_t valley_type{};
	public:
		int32_t collect_tax{};
	public:
		int32_t collect_count{};

	public:
		mrpc_blackiron_collect_tax_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blackiron_collect_tax_cs, tag)
		{
		}
		mrpc_blackiron_collect_tax_cs() : RpcPacket(mpe_rpc_cmd::blackiron_collect_tax_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &valley_type);
			protocol::SerializeType(pBuffer, &collect_tax);
			protocol::SerializeType(pBuffer, &collect_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_blackiron_collect_tax_sc : public RpcPacket 
	{

	public:
		mrpc_blackiron_collect_tax_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blackiron_collect_tax_sc, tag)
		{
		}
		mrpc_blackiron_collect_tax_sc() : RpcPacket(mpe_rpc_cmd::blackiron_collect_tax_sc)
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
