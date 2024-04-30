#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_league_rank.h"

namespace mir3d
{
	class mrpc_guild_shipwar_info_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t guid{};
	public:
		std::string guild_name{};
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t gid{};

	public:
		mrpc_guild_shipwar_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_shipwar_info_cs, tag)
		{
		}
		mrpc_guild_shipwar_info_cs() : RpcPacket(mpe_rpc_cmd::guild_shipwar_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_shipwar_info_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		mpe_guild_shipwar_state state{};
	public:
		int64_t match_number{};
	public:
		mpe_match_state result{};
	public:
		int32_t season{};
	public:
		int32_t round{};
	private:
		bool flag_guild_league = false;
		mps_guild_league_rank guild_league;	// 내문파 순위 정보
		mps_guild_league_rank* p_guild_league = nullptr;
	public:
		bool has_guild_league() const
		{
			return flag_guild_league;
		}
		mps_guild_league_rank* alloc_guild_league()
		{
			flag_guild_league = true;
			return &guild_league;
		}
		const mps_guild_league_rank* get_guild_league() const
		{
			if (true == flag_guild_league)
			{
				if (nullptr == p_guild_league)
				{
					return &guild_league;
				}
				return p_guild_league;
			}
			return nullptr;
		}
		void set_guild_league(mps_guild_league_rank* in_guild_league)
		{
			if (nullptr == p_guild_league)
			{
				p_guild_league = in_guild_league;
				flag_guild_league = true;
			}
		}

	public:
		mrpc_guild_shipwar_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_shipwar_info_sc, tag)
		{
		}
		mrpc_guild_shipwar_info_sc() : RpcPacket(mpe_rpc_cmd::guild_shipwar_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &match_number);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &season);
			protocol::SerializeType(pBuffer, &round);
			protocol::SerializeType(pBuffer, &flag_guild_league);
			if (true == flag_guild_league)
			{
				if (nullptr != p_guild_league)
					protocol::SerializeType(pBuffer, p_guild_league);
				else
					protocol::SerializeType(pBuffer, &guild_league);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
