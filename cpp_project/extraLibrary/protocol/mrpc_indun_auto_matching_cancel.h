#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_member_base.h"

namespace mir3d
{
	class mrpc_indun_auto_matching_cancel_cs : public RpcPacket 
	{
	public:
		std::vector<mps_party_member_base> list_member{};
	public:
		int32_t tid{};
	public:
		int64_t cuid{};

	public:
		mrpc_indun_auto_matching_cancel_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::indun_auto_matching_cancel_cs, tag)
		{
		}
		mrpc_indun_auto_matching_cancel_cs() : RpcPacket(mpe_rpc_cmd::indun_auto_matching_cancel_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_member);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_indun_auto_matching_cancel_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		bool is_auto_matching_out{};	// // 자동매칭에서 완전히 빠져나가는지 여부 (true : 자동매칭 완전 취소 false : 다시 매칭중 상태로)
	public:
		mrpce_group_type group_type{};

	public:
		mrpc_indun_auto_matching_cancel_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::indun_auto_matching_cancel_sc, tag)
		{
		}
		mrpc_indun_auto_matching_cancel_sc() : RpcPacket(mpe_rpc_cmd::indun_auto_matching_cancel_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &is_auto_matching_out);
			protocol::SerializeEnum(pBuffer, &group_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
