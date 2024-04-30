#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_league_rank.h"
#include "struct/mps_guild_league_rank.h"

namespace mir3d
{
	class mweb_guild_league_rank_cs : public WebBasePacket 	// gate에서 삭제
	{
	public:
		mpe_guild_rank_type type{};
	public:
		int64_t guid{};

	public:
		mweb_guild_league_rank_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_guild_league_rank_sc : public WebBasePacket 	// gate에서 삭제
	{
	public:
		std::vector<mps_guild_league_rank> list_rank{};
	private:
		bool flag_my_rank = false;
		mps_guild_league_rank my_rank;
		mps_guild_league_rank* p_my_rank = nullptr;
	public:
		bool has_my_rank() const
		{
			return flag_my_rank;
		}
		mps_guild_league_rank* alloc_my_rank()
		{
			flag_my_rank = true;
			return &my_rank;
		}
		const mps_guild_league_rank* get_my_rank() const
		{
			if (true == flag_my_rank)
			{
				if (nullptr == p_my_rank)
				{
					return &my_rank;
				}
				return p_my_rank;
			}
			return nullptr;
		}
		void set_my_rank(mps_guild_league_rank* in_my_rank)
		{
			if (nullptr == p_my_rank)
			{
				p_my_rank = in_my_rank;
				flag_my_rank = true;
			}
		}

	public:
		mweb_guild_league_rank_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_rank);
			protocol::SerializeType(pBuffer, &flag_my_rank);
			if (true == flag_my_rank)
			{
				if (nullptr != p_my_rank)
					protocol::SerializeType(pBuffer, p_my_rank);
				else
					protocol::SerializeType(pBuffer, &my_rank);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
