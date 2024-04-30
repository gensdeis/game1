#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_league_rank.h"

namespace mir3d
{
	class mp_guild_shipwar_info_cs : public BasePacket 
	{

	public:
		mp_guild_shipwar_info_cs() : BasePacket(mpe_cmd::guild_shipwar_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_guild_shipwar_info_sc : public BasePacket 
	{
	public:
		mpe_guild_shipwar_state state{};	// 전장상태
	public:
		mpe_match_state result{};	// 매칭상태
	public:
		int64_t match_number{};
	public:
		int32_t season{};
	public:
		int32_t round{};
	private:
		bool flag_guild_league = false;
		mps_guild_league_rank guild_league;	// 내문파 리그정보
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
		mp_guild_shipwar_info_sc() : BasePacket(mpe_cmd::guild_shipwar_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &match_number);
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
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
