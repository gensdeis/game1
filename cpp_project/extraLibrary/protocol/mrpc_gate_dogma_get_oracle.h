#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gate_dogma_get_oracle_cs : public RpcPacket 	// oracle 정보 조회
	{
	public:
		int64_t key{};
	public:
		std::string player_key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mrpc_gate_dogma_get_oracle_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_dogma_get_oracle_cs, tag)
		{
		}
		mrpc_gate_dogma_get_oracle_cs() : RpcPacket(mpe_rpc_cmd::gate_dogma_get_oracle_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &player_key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_dogma_get_oracle_sc : public RpcPacket 	// oracle 정보 조회
	{
	public:
		int64_t key{};
	public:
		int32_t result{};
	public:
		int32_t oracle{};

	public:
		mrpc_gate_dogma_get_oracle_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_dogma_get_oracle_sc, tag)
		{
		}
		mrpc_gate_dogma_get_oracle_sc() : RpcPacket(mpe_rpc_cmd::gate_dogma_get_oracle_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &oracle);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
