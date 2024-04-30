#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_purchase_info.h"

namespace mir3d
{
	class mrpc_gate_dogma_pay_start_cs : public RpcPacket 	// dogma 결제 시작
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
		std::string user_address{};	// 유저 월렛 주소
	public:
		std::string user_agent{};
	public:
		std::vector<mps_purchase_info> purchase_info{};
	public:
		std::string total_price{};
	public:
		std::string ip_address{};
	public:
		std::string column{};
	public:
		int32_t oracle{};

	public:
		mrpc_gate_dogma_pay_start_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_dogma_pay_start_cs, tag)
		{
		}
		mrpc_gate_dogma_pay_start_cs() : RpcPacket(mpe_rpc_cmd::gate_dogma_pay_start_cs)
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
			protocol::SerializeType(pBuffer, &user_address);
			protocol::SerializeType(pBuffer, &user_agent);
			protocol::SerializeType(pBuffer, &purchase_info);
			protocol::SerializeType(pBuffer, &total_price);
			protocol::SerializeType(pBuffer, &ip_address);
			protocol::SerializeType(pBuffer, &column);
			protocol::SerializeType(pBuffer, &oracle);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_dogma_pay_start_sc : public RpcPacket 	// dogma 결제 시작
	{
	public:
		int64_t key{};
	public:
		int32_t code{};
	public:
		int32_t result{};
	public:
		std::string pay_id{};	// pay id

	public:
		mrpc_gate_dogma_pay_start_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_dogma_pay_start_sc, tag)
		{
		}
		mrpc_gate_dogma_pay_start_sc() : RpcPacket(mpe_rpc_cmd::gate_dogma_pay_start_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &code);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &pay_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
