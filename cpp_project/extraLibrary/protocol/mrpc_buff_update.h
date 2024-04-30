#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_buff_update_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t buff_uid{};
	public:
		int64_t time{};

	public:
		mrpc_buff_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::buff_update_cs, tag)
		{
		}
		mrpc_buff_update_cs() : RpcPacket(mpe_rpc_cmd::buff_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &buff_uid);
			protocol::SerializeType(pBuffer, &time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_buff_update_sc : public RpcPacket 
	{

	public:
		mrpc_buff_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::buff_update_sc, tag)
		{
		}
		mrpc_buff_update_sc() : RpcPacket(mpe_rpc_cmd::buff_update_sc)
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
