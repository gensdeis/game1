#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_channel_remove_cs : public RpcPacket 
	{
	public:
		int64_t channel_uid{};

	public:
		mrpc_channel_remove_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::channel_remove_cs, tag)
		{
		}
		mrpc_channel_remove_cs() : RpcPacket(mpe_rpc_cmd::channel_remove_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &channel_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_channel_remove_sc : public RpcPacket 
	{
	public:
		int64_t channel_uid{};

	public:
		mrpc_channel_remove_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::channel_remove_sc, tag)
		{
		}
		mrpc_channel_remove_sc() : RpcPacket(mpe_rpc_cmd::channel_remove_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &channel_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
