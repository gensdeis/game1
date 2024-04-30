#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_party_leave_alert_by_indun_kick_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t puid{};	// "파티 uid"
	public:
		int64_t indun_uid{};	// "인던 uid"
	public:
		mpe_error reason{};

	public:
		mrpc_party_leave_alert_by_indun_kick_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_leave_alert_by_indun_kick_cs, tag)
		{
		}
		mrpc_party_leave_alert_by_indun_kick_cs() : RpcPacket(mpe_rpc_cmd::party_leave_alert_by_indun_kick_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeEnum(pBuffer, &reason);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_party_leave_alert_by_indun_kick_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t indun_uid{};	// "인던 uid"
	public:
		mpe_error reason{};	// "킥 사유. mpe_error 메세지."

	public:
		mrpc_party_leave_alert_by_indun_kick_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::party_leave_alert_by_indun_kick_sc, tag)
		{
		}
		mrpc_party_leave_alert_by_indun_kick_sc() : RpcPacket(mpe_rpc_cmd::party_leave_alert_by_indun_kick_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeEnum(pBuffer, &reason);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
