#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_wemix_shop_history.h"

namespace mir3d
{
	class mrpc_gate_get_wemix_history_cs : public RpcPacket 	// 위믹스 상점 내역 조회
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mrpc_gate_get_wemix_history_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_get_wemix_history_cs, tag)
		{
		}
		mrpc_gate_get_wemix_history_cs() : RpcPacket(mpe_rpc_cmd::gate_get_wemix_history_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_get_wemix_history_sc : public RpcPacket 	// 위믹스 상점 내역 조회
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_wemix_shop_history> shop_history{};

	public:
		mrpc_gate_get_wemix_history_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_get_wemix_history_sc, tag)
		{
		}
		mrpc_gate_get_wemix_history_sc() : RpcPacket(mpe_rpc_cmd::gate_get_wemix_history_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &shop_history);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
