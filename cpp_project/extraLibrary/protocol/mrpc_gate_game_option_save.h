#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_game_option_save_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		mpe_clinet_platform platform{};
	public:
		std::vector<uint8_t> option_data{};
	public:
		std::string option_hash{};

	public:
		mrpc_gate_game_option_save_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_game_option_save_cs, tag)
		{
		}
		mrpc_gate_game_option_save_cs() : RpcPacket(mpe_rpc_cmd::gate_game_option_save_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &platform);
			protocol::SerializeType(pBuffer, &option_data);
			protocol::SerializeType(pBuffer, &option_hash);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_game_option_save_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_gate_game_option_save_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_game_option_save_sc, tag)
		{
		}
		mrpc_gate_game_option_save_sc() : RpcPacket(mpe_rpc_cmd::gate_game_option_save_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
