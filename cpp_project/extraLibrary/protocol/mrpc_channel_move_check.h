#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_channel_move_check_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t zone_id{};
	public:
		int32_t map_object_data_table_id{};
	public:
		int32_t item_id{};

	public:
		mrpc_channel_move_check_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::channel_move_check_cs, tag)
		{
		}
		mrpc_channel_move_check_cs() : RpcPacket(mpe_rpc_cmd::channel_move_check_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &map_object_data_table_id);
			protocol::SerializeType(pBuffer, &item_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_channel_move_check_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int32_t map_object_data_table_id{};
	public:
		int32_t item_id{};
	public:
		uint16_t channel_id{};

	public:
		mrpc_channel_move_check_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::channel_move_check_sc, tag)
		{
		}
		mrpc_channel_move_check_sc() : RpcPacket(mpe_rpc_cmd::channel_move_check_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &map_object_data_table_id);
			protocol::SerializeType(pBuffer, &item_id);
			protocol::SerializeType(pBuffer, &channel_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
