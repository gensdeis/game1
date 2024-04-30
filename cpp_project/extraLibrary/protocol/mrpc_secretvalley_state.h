#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_secretvalley_owner_info.h"
#include "struct/mrpcs_occupationwar_war_map_info.h"
#include "struct/mrpcs_occupationwar_owner_disqualify.h"

namespace mir3d
{
	class mrpc_secretvalley_state_cs : public RpcPacket 
	{
	public:
		mpe_secretvalley_state state{};

	public:
		mrpc_secretvalley_state_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::secretvalley_state_cs, tag)
		{
		}
		mrpc_secretvalley_state_cs() : RpcPacket(mpe_rpc_cmd::secretvalley_state_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_secretvalley_state_sc : public RpcPacket 
	{
	public:
		mpe_secretvalley_state state{};
	public:
		int32_t gid{};
	public:
		mpe_occupationwar_map_type map_type{};
	public:
		int32_t zone_id{};
	public:
		int64_t channel_uid{};
	public:
		int32_t start_time{};
	public:
		int32_t end_time{};
	private:
		bool flag_owner_info = false;
		mps_secretvalley_owner_info owner_info;
		mps_secretvalley_owner_info* p_owner_info = nullptr;
	public:
		bool has_owner_info() const
		{
			return flag_owner_info;
		}
		mps_secretvalley_owner_info* alloc_owner_info()
		{
			flag_owner_info = true;
			return &owner_info;
		}
		const mps_secretvalley_owner_info* get_owner_info() const
		{
			if (true == flag_owner_info)
			{
				if (nullptr == p_owner_info)
				{
					return &owner_info;
				}
				return p_owner_info;
			}
			return nullptr;
		}
		void set_owner_info(mps_secretvalley_owner_info* in_owner_info)
		{
			if (nullptr == p_owner_info)
			{
				p_owner_info = in_owner_info;
				flag_owner_info = true;
			}
		}
	public:
		bool decide{};
	public:
		bool occupationwar_war_map{};
	public:
		std::vector<mrpcs_occupationwar_war_map_info> list_map_guild{};
	public:
		std::vector<mrpcs_occupationwar_owner_disqualify> list_disqualify{};	// 자격발탈 목록
	public:
		std::vector<int64_t> list_guild_skill{};

	public:
		mrpc_secretvalley_state_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::secretvalley_state_sc, tag)
		{
		}
		mrpc_secretvalley_state_sc() : RpcPacket(mpe_rpc_cmd::secretvalley_state_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeEnum(pBuffer, &map_type);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &start_time);
			protocol::SerializeType(pBuffer, &end_time);
			protocol::SerializeType(pBuffer, &flag_owner_info);
			if (true == flag_owner_info)
			{
				if (nullptr != p_owner_info)
					protocol::SerializeType(pBuffer, p_owner_info);
				else
					protocol::SerializeType(pBuffer, &owner_info);
			}
			protocol::SerializeType(pBuffer, &decide);
			protocol::SerializeType(pBuffer, &occupationwar_war_map);
			protocol::SerializeType(pBuffer, &list_map_guild);
			protocol::SerializeType(pBuffer, &list_disqualify);
			protocol::SerializeType(pBuffer, &list_guild_skill);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
