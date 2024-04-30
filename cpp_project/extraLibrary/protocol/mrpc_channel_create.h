#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_channel_create_cs : public RpcPacket 
	{
	public:
		int32_t table_id{};
	public:
		short max_user_count{};
	public:
		uint8_t worker_index{};
	public:
		int32_t id{};
	public:
		int64_t channel_uid{};

	public:
		mrpc_channel_create_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::channel_create_cs, tag)
		{
		}
		mrpc_channel_create_cs() : RpcPacket(mpe_rpc_cmd::channel_create_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &max_user_count);
			protocol::SerializeType(pBuffer, &worker_index);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &channel_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_channel_create_sc : public RpcPacket 
	{

	public:
		mrpc_channel_create_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::channel_create_sc, tag)
		{
		}
		mrpc_channel_create_sc() : RpcPacket(mpe_rpc_cmd::channel_create_sc)
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
