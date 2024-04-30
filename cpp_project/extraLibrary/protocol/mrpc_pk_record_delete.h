#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_pk_record_delete_cs : public RpcPacket 	// pk 기록삭제
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t delete_pk_record_id{};

	public:
		mrpc_pk_record_delete_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pk_record_delete_cs, tag)
		{
		}
		mrpc_pk_record_delete_cs() : RpcPacket(mpe_rpc_cmd::pk_record_delete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &delete_pk_record_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_pk_record_delete_sc : public RpcPacket 	// pk 기록삭제
	{
	public:
		int64_t key{};

	public:
		mrpc_pk_record_delete_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::pk_record_delete_sc, tag)
		{
		}
		mrpc_pk_record_delete_sc() : RpcPacket(mpe_rpc_cmd::pk_record_delete_sc)
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
