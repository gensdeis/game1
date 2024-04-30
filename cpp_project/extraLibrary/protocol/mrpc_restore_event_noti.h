#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_restore_noti.h"

namespace mir3d
{
	class mrpc_restore_event_noti_cs : public RpcPacket 	// 신룡의축복 noti
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};

	public:
		mrpc_restore_event_noti_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::restore_event_noti_cs, tag)
		{
		}
		mrpc_restore_event_noti_cs() : RpcPacket(mpe_rpc_cmd::restore_event_noti_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_restore_event_noti_sc : public RpcPacket 	// 신룡의축복 noti
	{
	public:
		std::vector<mps_restore_noti> noti_list{};	// 알림 list
	public:
		int64_t key{};

	public:
		mrpc_restore_event_noti_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::restore_event_noti_sc, tag)
		{
		}
		mrpc_restore_event_noti_sc() : RpcPacket(mpe_rpc_cmd::restore_event_noti_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &noti_list);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
