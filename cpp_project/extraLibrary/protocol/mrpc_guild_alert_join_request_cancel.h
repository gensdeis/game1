#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_alert_join_request_cancel_cs : public RpcPacket 	// // 가입요청 취소 알림 패킷
	{

	public:
		mrpc_guild_alert_join_request_cancel_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_join_request_cancel_cs, tag)
		{
		}
		mrpc_guild_alert_join_request_cancel_cs() : RpcPacket(mpe_rpc_cmd::guild_alert_join_request_cancel_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_alert_join_request_cancel_sc : public RpcPacket 	// // 가입요청 취소 알림 패킷
	{
	public:
		std::vector<int64_t> list_member_having_permission{};	// // 가입처리 가능한 멤버리스트
	public:
		int64_t request_cuid{};	// // 가입요청한 유저 id

	public:
		mrpc_guild_alert_join_request_cancel_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_alert_join_request_cancel_sc, tag)
		{
		}
		mrpc_guild_alert_join_request_cancel_sc() : RpcPacket(mpe_rpc_cmd::guild_alert_join_request_cancel_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_member_having_permission);
			protocol::SerializeType(pBuffer, &request_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
