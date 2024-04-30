#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_pk_setup_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t setup{};

	public:
		mrpc_pk_setup_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pk_setup_cs, tag)
		{
		}
		mrpc_pk_setup_cs() : RpcPacket(mpe_rpc_cmd::pk_setup_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &setup);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_pk_setup_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_pk_setup_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pk_setup_sc, tag)
		{
		}
		mrpc_pk_setup_sc() : RpcPacket(mpe_rpc_cmd::pk_setup_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
