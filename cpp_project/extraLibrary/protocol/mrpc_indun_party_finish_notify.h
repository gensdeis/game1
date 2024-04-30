#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_indun_party_finish_notify_cs : public RpcPacket 	// "파티/보스토벌 클리어했을때 인던에서 알림(finish 상태가 될때)"
	{
	public:
		int64_t puid{};	// 파티uid

	public:
		mrpc_indun_party_finish_notify_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::indun_party_finish_notify_cs, tag)
		{
		}
		mrpc_indun_party_finish_notify_cs() : RpcPacket(mpe_rpc_cmd::indun_party_finish_notify_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &puid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_indun_party_finish_notify_sc : public RpcPacket 	// "파티/보스토벌 클리어했을때 인던에서 알림(finish 상태가 될때)"
	{

	public:
		mrpc_indun_party_finish_notify_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::indun_party_finish_notify_sc, tag)
		{
		}
		mrpc_indun_party_finish_notify_sc() : RpcPacket(mpe_rpc_cmd::indun_party_finish_notify_sc)
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

}
