#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_server_use_count_cs : public RpcPacket 
	{
	public:
		int64_t channel_uid{};
	public:
		mrpce_server_type server_type{};
	public:
		int32_t server_index{};
	public:
		int32_t table_id{};
	public:
		short use_count{};
	public:
		short server_play_count{};
	public:
		int64_t auid{};
	public:
		bool is_first{};

	public:
		mrpc_server_use_count_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_use_count_cs, tag)
		{
		}
		mrpc_server_use_count_cs() : RpcPacket(mpe_rpc_cmd::server_use_count_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeType(pBuffer, &table_id);
			protocol::SerializeType(pBuffer, &use_count);
			protocol::SerializeType(pBuffer, &server_play_count);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &is_first);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_server_use_count_sc : public RpcPacket 
	{

	public:
		mrpc_server_use_count_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_use_count_sc, tag)
		{
		}
		mrpc_server_use_count_sc() : RpcPacket(mpe_rpc_cmd::server_use_count_sc)
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
