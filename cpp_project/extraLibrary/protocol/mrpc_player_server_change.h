#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_player_server_change_cs : public RpcPacket 
	{
	public:
		int64_t auid{};
	public:
		mrpce_server_type server_type{};
	public:
		int32_t server_index{};
	public:
		int64_t channel_uid{};
	public:
		int32_t indun_tid{};

	public:
		mrpc_player_server_change_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::player_server_change_cs, tag)
		{
		}
		mrpc_player_server_change_cs() : RpcPacket(mpe_rpc_cmd::player_server_change_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &server_index);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &indun_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_player_server_change_sc : public RpcPacket 
	{

	public:
		mrpc_player_server_change_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::player_server_change_sc, tag)
		{
		}
		mrpc_player_server_change_sc() : RpcPacket(mpe_rpc_cmd::player_server_change_sc)
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
