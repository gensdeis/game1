#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_buff_delete_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t buff_id{};

	public:
		mrpc_buff_delete_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::buff_delete_cs, tag)
		{
		}
		mrpc_buff_delete_cs() : RpcPacket(mpe_rpc_cmd::buff_delete_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &buff_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_buff_delete_sc : public RpcPacket 
	{

	public:
		mrpc_buff_delete_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::buff_delete_sc, tag)
		{
		}
		mrpc_buff_delete_sc() : RpcPacket(mpe_rpc_cmd::buff_delete_sc)
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
