#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_street_stall_fees.h"

namespace mir3d
{
	class mrpc_street_stall_end_cs : public RpcPacket 	// // 개인 노점 종료
	{
	public:
		int64_t suid{};	// // 개인 노점 uid
	public:
		int64_t cuid{};
	public:
		int32_t use_count{};	// // 거래 가능 count
	public:
		std::vector<mps_street_stall_fees> total_fees{};	// // 누적 수수료
	public:
		int64_t reset_time{};
	public:
		int64_t cool_time{};
	public:
		bool is_send_owner{};
	public:
		int64_t life_time{};	// // 남은시간

	public:
		mrpc_street_stall_end_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::street_stall_end_cs, tag)
		{
		}
		mrpc_street_stall_end_cs() : RpcPacket(mpe_rpc_cmd::street_stall_end_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &suid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &use_count);
			protocol::SerializeType(pBuffer, &total_fees);
			protocol::SerializeType(pBuffer, &reset_time);
			protocol::SerializeType(pBuffer, &cool_time);
			protocol::SerializeType(pBuffer, &is_send_owner);
			protocol::SerializeType(pBuffer, &life_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_street_stall_end_sc : public RpcPacket 	// // 개인 노점 종료
	{
	public:
		int64_t cuid{};
	public:
		int64_t suid{};

	public:
		mrpc_street_stall_end_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::street_stall_end_sc, tag)
		{
		}
		mrpc_street_stall_end_sc() : RpcPacket(mpe_rpc_cmd::street_stall_end_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &suid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
