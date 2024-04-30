#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_member_base.h"

namespace mir3d
{
	class mrpc_indun_auto_matching_complete_cs : public RpcPacket 	// // 인던 매칭 완료 알림
	{

	public:
		mrpc_indun_auto_matching_complete_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::indun_auto_matching_complete_cs, tag)
		{
		}
		mrpc_indun_auto_matching_complete_cs() : RpcPacket(mpe_rpc_cmd::indun_auto_matching_complete_cs)
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

	class mrpc_indun_auto_matching_complete_sc : public RpcPacket 	// // 인던 매칭 완료 알림
	{
	public:
		int64_t cuid{};
	public:
		int32_t tid{};
	public:
		std::vector<mps_party_member_base> list_member{};

	public:
		mrpc_indun_auto_matching_complete_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::indun_auto_matching_complete_sc, tag)
		{
		}
		mrpc_indun_auto_matching_complete_sc() : RpcPacket(mpe_rpc_cmd::indun_auto_matching_complete_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &list_member);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
