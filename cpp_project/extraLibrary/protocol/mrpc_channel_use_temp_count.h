#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_channel_use_temp_count_cs : public RpcPacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t channel_uid{};

	public:
		mrpc_channel_use_temp_count_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::channel_use_temp_count_cs, tag)
		{
		}
		mrpc_channel_use_temp_count_cs() : RpcPacket(mpe_rpc_cmd::channel_use_temp_count_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &channel_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_channel_use_temp_count_sc : public RpcPacket 
	{
	public:
		int64_t channel_uid{};
	public:
		short count{};

	public:
		mrpc_channel_use_temp_count_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::channel_use_temp_count_sc, tag)
		{
		}
		mrpc_channel_use_temp_count_sc() : RpcPacket(mpe_rpc_cmd::channel_use_temp_count_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
