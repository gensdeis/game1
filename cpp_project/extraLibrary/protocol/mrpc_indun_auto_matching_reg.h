#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_party_member_base.h"

namespace mir3d
{
	class mrpc_indun_auto_matching_reg_cs : public RpcPacket 	// // 인던 매칭 등록 요청
	{
	public:
		std::vector<mps_party_member_base> list_member{};
	public:
		int32_t tid{};
	public:
		int32_t category{};
	public:
		mrpce_group_type group_type{};

	public:
		mrpc_indun_auto_matching_reg_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::indun_auto_matching_reg_cs, tag)
		{
		}
		mrpc_indun_auto_matching_reg_cs() : RpcPacket(mpe_rpc_cmd::indun_auto_matching_reg_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_member);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &category);
			protocol::SerializeEnum(pBuffer, &group_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_indun_auto_matching_reg_sc : public RpcPacket 	// // 인던 매칭 등록 요청
	{
	public:
		int64_t cuid{};
	public:
		int32_t tid{};

	public:
		mrpc_indun_auto_matching_reg_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::indun_auto_matching_reg_sc, tag)
		{
		}
		mrpc_indun_auto_matching_reg_sc() : RpcPacket(mpe_rpc_cmd::indun_auto_matching_reg_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
