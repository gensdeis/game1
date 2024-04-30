#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_npc_buy_count.h"

namespace mir3d
{
	class mrpc_blood_dedicate_status_cs : public RpcPacket 	// 봉혈 현황 UI
	{
	public:
		int64_t key{};	// 세션 아이디
	public:
		int64_t auid{};	// 계정 아이디
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		int32_t shop_group_id{};	// shop_table 그룹 아이디
	public:
		int32_t fixed_object_id{};	// 봉혈 오브젝트 아이디

	public:
		mrpc_blood_dedicate_status_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blood_dedicate_status_cs, tag)
		{
		}
		mrpc_blood_dedicate_status_cs() : RpcPacket(mpe_rpc_cmd::blood_dedicate_status_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &shop_group_id);
			protocol::SerializeType(pBuffer, &fixed_object_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_blood_dedicate_status_sc : public RpcPacket 	// 봉혈 현황 UI
	{
	public:
		std::vector<mps_npc_buy_count> buy_count_list{};	// 봉혈 교환횟수 정보
	public:
		int64_t key{};	// 세션 아이디
	public:
		int64_t auid{};	// 계정 아이디
	public:
		int64_t cuid{};	// 캐릭터 아이디
	public:
		int32_t shop_group_id{};	// shopt_table 그룹 아이디
	public:
		int32_t fixed_object_id{};	// 봉혈 오브젝트 아이디

	public:
		mrpc_blood_dedicate_status_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blood_dedicate_status_sc, tag)
		{
		}
		mrpc_blood_dedicate_status_sc() : RpcPacket(mpe_rpc_cmd::blood_dedicate_status_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &buy_count_list);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &shop_group_id);
			protocol::SerializeType(pBuffer, &fixed_object_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
