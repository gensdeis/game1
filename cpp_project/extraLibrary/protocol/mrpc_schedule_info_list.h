#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_schedule_info.h"
#include "struct/mps_schedule_info.h"
#include "struct/mps_schedule_info.h"
#include "struct/mps_schedule_info.h"
#include "struct/mps_schedule_info.h"

namespace mir3d
{
	class mrpc_schedule_info_list_cs : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_schedule_info_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::schedule_info_list_cs, tag)
		{
		}
		mrpc_schedule_info_list_cs() : RpcPacket(mpe_rpc_cmd::schedule_info_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_schedule_info_list_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_schedule_info> world_boss_info{};	// 월드보스
	public:
		std::vector<mps_schedule_info> siege_warfare_info{};	// 공성전
	public:
		std::vector<mps_schedule_info> guild_shipwar_info{};	// 혈범전장
	public:
		std::vector<mps_schedule_info> secretvalley_info{};	// 비곡점령전
	public:
		std::vector<mps_schedule_info> arena_battle_info{};	// 수라전장

	public:
		mrpc_schedule_info_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::schedule_info_list_sc, tag)
		{
		}
		mrpc_schedule_info_list_sc() : RpcPacket(mpe_rpc_cmd::schedule_info_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &world_boss_info);
			protocol::SerializeType(pBuffer, &siege_warfare_info);
			protocol::SerializeType(pBuffer, &guild_shipwar_info);
			protocol::SerializeType(pBuffer, &secretvalley_info);
			protocol::SerializeType(pBuffer, &arena_battle_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
