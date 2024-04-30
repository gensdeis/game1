#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_occupationwar_challenge_guild_info.h"

namespace mir3d
{
	class mrpc_gate_occupationwar_challenge_request_list_cs : public RpcPacket 	// 비곡점령전 신청 내역 조회
	{
	public:
		int64_t key{};

	public:
		mrpc_gate_occupationwar_challenge_request_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_occupationwar_challenge_request_list_cs, tag)
		{
		}
		mrpc_gate_occupationwar_challenge_request_list_cs() : RpcPacket(mpe_rpc_cmd::gate_occupationwar_challenge_request_list_cs)
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

	class mrpc_gate_occupationwar_challenge_request_list_sc : public RpcPacket 	// 비곡점령전 신청 내역 조회
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_occupationwar_challenge_guild_info> list{};

	public:
		mrpc_gate_occupationwar_challenge_request_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_occupationwar_challenge_request_list_sc, tag)
		{
		}
		mrpc_gate_occupationwar_challenge_request_list_sc() : RpcPacket(mpe_rpc_cmd::gate_occupationwar_challenge_request_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
