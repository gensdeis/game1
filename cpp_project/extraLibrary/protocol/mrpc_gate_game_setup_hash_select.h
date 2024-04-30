#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_game_setup_hash_select_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::string game_setup_hash{};
	public:
		mpe_clinet_platform platform{};
	public:
		std::string game_option_hash{};

	public:
		mrpc_gate_game_setup_hash_select_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_game_setup_hash_select_cs, tag)
		{
		}
		mrpc_gate_game_setup_hash_select_cs() : RpcPacket(mpe_rpc_cmd::gate_game_setup_hash_select_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &game_setup_hash);
			protocol::SerializeEnum(pBuffer, &platform);
			protocol::SerializeType(pBuffer, &game_option_hash);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_game_setup_hash_select_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		bool game_setup{};
	public:
		bool game_option{};

	public:
		mrpc_gate_game_setup_hash_select_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_game_setup_hash_select_sc, tag)
		{
		}
		mrpc_gate_game_setup_hash_select_sc() : RpcPacket(mpe_rpc_cmd::gate_game_setup_hash_select_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &game_setup);
			protocol::SerializeType(pBuffer, &game_option);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
