#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_item_id.h"

namespace mir3d
{
	class mrpc_blackiron_sell_info_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		uint8_t secretvalley_type{};
	public:
		std::vector<int32_t> sell_list{};	// 판매목록

	public:
		mrpc_blackiron_sell_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blackiron_sell_info_cs, tag)
		{
		}
		mrpc_blackiron_sell_info_cs() : RpcPacket(mpe_rpc_cmd::blackiron_sell_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &secretvalley_type);
			protocol::SerializeType(pBuffer, &sell_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_blackiron_sell_info_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_item_id> sell_list{};	// 판매정보
	public:
		int32_t sell_end_time{};	// 판매종료 시간
	public:
		int32_t sell_regist_key{};	// 판매등록 키값
	public:
		int32_t sell_total_count{};	// 판매량
	public:
		std::string guild_name{};	// 점령중인문파이름
	public:
		std::vector<uint8_t> guild_mark{};	// 점령중인문파문장

	public:
		mrpc_blackiron_sell_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blackiron_sell_info_sc, tag)
		{
		}
		mrpc_blackiron_sell_info_sc() : RpcPacket(mpe_rpc_cmd::blackiron_sell_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &sell_list);
			protocol::SerializeType(pBuffer, &sell_end_time);
			protocol::SerializeType(pBuffer, &sell_regist_key);
			protocol::SerializeType(pBuffer, &sell_total_count);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &guild_mark);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
