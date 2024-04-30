#pragma once
#include <vector>
#include <string>
#include "mrpcs_guild_shipwar_info.h"
#include "mrpcs_guild_shipwar_info.h"

namespace mir3d
{
	class mrpcs_guild_shipwar_matchup 
	{
	public:
		int64_t match_number{};
	private:
		bool flag_guild_0 = false;
		mrpcs_guild_shipwar_info guild_0;
		mrpcs_guild_shipwar_info* p_guild_0 = nullptr;
	public:
		bool has_guild_0() const
		{
			return flag_guild_0;
		}
		mrpcs_guild_shipwar_info* alloc_guild_0()
		{
			flag_guild_0 = true;
			return &guild_0;
		}
		const mrpcs_guild_shipwar_info* get_guild_0() const
		{
			if (true == flag_guild_0)
			{
				if (nullptr == p_guild_0)
				{
					return &guild_0;
				}
				return p_guild_0;
			}
			return nullptr;
		}
		void set_guild_0(mrpcs_guild_shipwar_info* in_guild_0)
		{
			if (nullptr == p_guild_0)
			{
				p_guild_0 = in_guild_0;
				flag_guild_0 = true;
			}
		}
	private:
		bool flag_guild_1 = false;
		mrpcs_guild_shipwar_info guild_1;
		mrpcs_guild_shipwar_info* p_guild_1 = nullptr;
	public:
		bool has_guild_1() const
		{
			return flag_guild_1;
		}
		mrpcs_guild_shipwar_info* alloc_guild_1()
		{
			flag_guild_1 = true;
			return &guild_1;
		}
		const mrpcs_guild_shipwar_info* get_guild_1() const
		{
			if (true == flag_guild_1)
			{
				if (nullptr == p_guild_1)
				{
					return &guild_1;
				}
				return p_guild_1;
			}
			return nullptr;
		}
		void set_guild_1(mrpcs_guild_shipwar_info* in_guild_1)
		{
			if (nullptr == p_guild_1)
			{
				p_guild_1 = in_guild_1;
				flag_guild_1 = true;
			}
		}

	public:
		mrpcs_guild_shipwar_matchup()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &match_number);
			protocol::SerializeType(pBuffer, &flag_guild_0);
			if (true == flag_guild_0)
			{
				if (nullptr != p_guild_0)
					protocol::SerializeType(pBuffer, p_guild_0);
				else
					protocol::SerializeType(pBuffer, &guild_0);
			}
			protocol::SerializeType(pBuffer, &flag_guild_1);
			if (true == flag_guild_1)
			{
				if (nullptr != p_guild_1)
					protocol::SerializeType(pBuffer, p_guild_1);
				else
					protocol::SerializeType(pBuffer, &guild_1);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
