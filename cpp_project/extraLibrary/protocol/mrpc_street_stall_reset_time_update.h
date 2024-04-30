#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_street_stall_reset_time_update_cs : public RpcPacket 	// // 개인 노점 reset time 업데이트
	{
	public:
		int64_t suid{};	// // 개인 노점 uid
	public:
		int64_t cuid{};
	public:
		int32_t use_count{};	// // 거래 가능 count
	public:
		int64_t reset_time{};
	public:
		bool is_send_owner{};

	public:
		mrpc_street_stall_reset_time_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::street_stall_reset_time_update_cs, tag)
		{
		}
		mrpc_street_stall_reset_time_update_cs() : RpcPacket(mpe_rpc_cmd::street_stall_reset_time_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &suid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &use_count);
			protocol::SerializeType(pBuffer, &reset_time);
			protocol::SerializeType(pBuffer, &is_send_owner);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_street_stall_reset_time_update_sc : public RpcPacket 	// // 개인 노점 reset time 업데이트
	{
	public:
		int64_t cuid{};
	public:
		int64_t suid{};
	public:
		int64_t channel_uid{};

	public:
		mrpc_street_stall_reset_time_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::street_stall_reset_time_update_sc, tag)
		{
		}
		mrpc_street_stall_reset_time_update_sc() : RpcPacket(mpe_rpc_cmd::street_stall_reset_time_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &suid);
			protocol::SerializeType(pBuffer, &channel_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
