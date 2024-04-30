#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_occupationwar_server_info_total.h"
#include "struct/mps_occupationwar_challenge_guild_info.h"
#include "struct/mrpcs_occupationwar_owner_disqualify.h"

namespace mir3d
{
	class mrpc_global_occupationwar_war_schedule_noti_cs : public RpcPacket 
	{

	public:
		mrpc_global_occupationwar_war_schedule_noti_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_occupationwar_war_schedule_noti_cs, tag)
		{
		}
		mrpc_global_occupationwar_war_schedule_noti_cs() : RpcPacket(mpe_rpc_cmd::global_occupationwar_war_schedule_noti_cs)
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

	class mrpc_global_occupationwar_war_schedule_noti_sc : public RpcPacket 
	{
	public:
		mrpce_occupationwar_war_schedule_noti_type type{};
	public:
		bool rerun_schedule{};
	public:
		int32_t time_remain{};
	public:
		int32_t time_start{};
	public:
		int32_t time_finish{};
	public:
		int64_t next_occupationwar_uid{};
	public:
		std::vector<mrpcs_occupationwar_server_info_total> list_decide{};
	public:
		std::vector<mps_occupationwar_challenge_guild_info> list_guild{};
	public:
		std::vector<mrpcs_occupationwar_owner_disqualify> list_disqualify{};
	public:
		std::vector<int64_t> list_guild_skill{};

	public:
		mrpc_global_occupationwar_war_schedule_noti_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_occupationwar_war_schedule_noti_sc, tag)
		{
		}
		mrpc_global_occupationwar_war_schedule_noti_sc() : RpcPacket(mpe_rpc_cmd::global_occupationwar_war_schedule_noti_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &rerun_schedule);
			protocol::SerializeType(pBuffer, &time_remain);
			protocol::SerializeType(pBuffer, &time_start);
			protocol::SerializeType(pBuffer, &time_finish);
			protocol::SerializeType(pBuffer, &next_occupationwar_uid);
			protocol::SerializeType(pBuffer, &list_decide);
			protocol::SerializeType(pBuffer, &list_guild);
			protocol::SerializeType(pBuffer, &list_disqualify);
			protocol::SerializeType(pBuffer, &list_guild_skill);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
