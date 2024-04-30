#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_shipwar_character.h"

namespace mir3d
{
	class mrpc_gate_shipwar_result_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t guid{};
	public:
		int64_t battle_uid{};
	public:
		int32_t season_round{};

	public:
		mrpc_gate_shipwar_result_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_shipwar_result_cs, tag)
		{
		}
		mrpc_gate_shipwar_result_cs() : RpcPacket(mpe_rpc_cmd::gate_shipwar_result_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &battle_uid);
			protocol::SerializeType(pBuffer, &season_round);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_shipwar_result_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_shipwar_character> list_info{};

	public:
		mrpc_gate_shipwar_result_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_shipwar_result_sc, tag)
		{
		}
		mrpc_gate_shipwar_result_sc() : RpcPacket(mpe_rpc_cmd::gate_shipwar_result_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &list_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
