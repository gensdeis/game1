#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_lobby_player_character_select_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		std::string access_token{};
	public:
		std::vector<int64_t> list{};	// 4개까지만 처리한다.

	public:
		mrpc_gate_lobby_player_character_select_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_lobby_player_character_select_cs, tag)
		{
		}
		mrpc_gate_lobby_player_character_select_cs() : RpcPacket(mpe_rpc_cmd::gate_lobby_player_character_select_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_lobby_player_character_select_sc : public RpcPacket 
	{
	public:
		int32_t result{};
	public:
		int64_t key{};

	public:
		mrpc_gate_lobby_player_character_select_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_lobby_player_character_select_sc, tag)
		{
		}
		mrpc_gate_lobby_player_character_select_sc() : RpcPacket(mpe_rpc_cmd::gate_lobby_player_character_select_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
