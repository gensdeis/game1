#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_pk_record_viewed_cs : public RpcPacket 	// 목록확인
	{
	public:
		int64_t cuid{};

	public:
		mrpc_pk_record_viewed_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pk_record_viewed_cs, tag)
		{
		}
		mrpc_pk_record_viewed_cs() : RpcPacket(mpe_rpc_cmd::pk_record_viewed_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_pk_record_viewed_sc : public RpcPacket 	// 목록확인
	{

	public:
		mrpc_pk_record_viewed_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pk_record_viewed_sc, tag)
		{
		}
		mrpc_pk_record_viewed_sc() : RpcPacket(mpe_rpc_cmd::pk_record_viewed_sc)
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
