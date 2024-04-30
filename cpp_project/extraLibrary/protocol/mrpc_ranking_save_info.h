#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_character_ranking_info.h"
#include "struct/mrpcs_guild_ranking_info.h"
#include "struct/mrpcs_profesion_ranking_info.h"

namespace mir3d
{
	class mrpc_ranking_save_info_cs : public RpcPacket 
	{
	public:
		int64_t uid{};
	public:
		mpe_ranking_type rank_type{};
	private:
		bool flag_character_ranking_info = false;
		mrpcs_character_ranking_info character_ranking_info;
		mrpcs_character_ranking_info* p_character_ranking_info = nullptr;
	public:
		bool has_character_ranking_info() const
		{
			return flag_character_ranking_info;
		}
		mrpcs_character_ranking_info* alloc_character_ranking_info()
		{
			flag_character_ranking_info = true;
			return &character_ranking_info;
		}
		const mrpcs_character_ranking_info* get_character_ranking_info() const
		{
			if (true == flag_character_ranking_info)
			{
				if (nullptr == p_character_ranking_info)
				{
					return &character_ranking_info;
				}
				return p_character_ranking_info;
			}
			return nullptr;
		}
		void set_character_ranking_info(mrpcs_character_ranking_info* in_character_ranking_info)
		{
			if (nullptr == p_character_ranking_info)
			{
				p_character_ranking_info = in_character_ranking_info;
				flag_character_ranking_info = true;
			}
		}
	private:
		bool flag_guild_ranking_info = false;
		mrpcs_guild_ranking_info guild_ranking_info;
		mrpcs_guild_ranking_info* p_guild_ranking_info = nullptr;
	public:
		bool has_guild_ranking_info() const
		{
			return flag_guild_ranking_info;
		}
		mrpcs_guild_ranking_info* alloc_guild_ranking_info()
		{
			flag_guild_ranking_info = true;
			return &guild_ranking_info;
		}
		const mrpcs_guild_ranking_info* get_guild_ranking_info() const
		{
			if (true == flag_guild_ranking_info)
			{
				if (nullptr == p_guild_ranking_info)
				{
					return &guild_ranking_info;
				}
				return p_guild_ranking_info;
			}
			return nullptr;
		}
		void set_guild_ranking_info(mrpcs_guild_ranking_info* in_guild_ranking_info)
		{
			if (nullptr == p_guild_ranking_info)
			{
				p_guild_ranking_info = in_guild_ranking_info;
				flag_guild_ranking_info = true;
			}
		}
	private:
		bool flag_profesion_ranking_info = false;
		mrpcs_profesion_ranking_info profesion_ranking_info;
		mrpcs_profesion_ranking_info* p_profesion_ranking_info = nullptr;
	public:
		bool has_profesion_ranking_info() const
		{
			return flag_profesion_ranking_info;
		}
		mrpcs_profesion_ranking_info* alloc_profesion_ranking_info()
		{
			flag_profesion_ranking_info = true;
			return &profesion_ranking_info;
		}
		const mrpcs_profesion_ranking_info* get_profesion_ranking_info() const
		{
			if (true == flag_profesion_ranking_info)
			{
				if (nullptr == p_profesion_ranking_info)
				{
					return &profesion_ranking_info;
				}
				return p_profesion_ranking_info;
			}
			return nullptr;
		}
		void set_profesion_ranking_info(mrpcs_profesion_ranking_info* in_profesion_ranking_info)
		{
			if (nullptr == p_profesion_ranking_info)
			{
				p_profesion_ranking_info = in_profesion_ranking_info;
				flag_profesion_ranking_info = true;
			}
		}

	public:
		mrpc_ranking_save_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::ranking_save_info_cs, tag)
		{
		}
		mrpc_ranking_save_info_cs() : RpcPacket(mpe_rpc_cmd::ranking_save_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeEnum(pBuffer, &rank_type);
			protocol::SerializeType(pBuffer, &flag_character_ranking_info);
			if (true == flag_character_ranking_info)
			{
				if (nullptr != p_character_ranking_info)
					protocol::SerializeType(pBuffer, p_character_ranking_info);
				else
					protocol::SerializeType(pBuffer, &character_ranking_info);
			}
			protocol::SerializeType(pBuffer, &flag_guild_ranking_info);
			if (true == flag_guild_ranking_info)
			{
				if (nullptr != p_guild_ranking_info)
					protocol::SerializeType(pBuffer, p_guild_ranking_info);
				else
					protocol::SerializeType(pBuffer, &guild_ranking_info);
			}
			protocol::SerializeType(pBuffer, &flag_profesion_ranking_info);
			if (true == flag_profesion_ranking_info)
			{
				if (nullptr != p_profesion_ranking_info)
					protocol::SerializeType(pBuffer, p_profesion_ranking_info);
				else
					protocol::SerializeType(pBuffer, &profesion_ranking_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_ranking_save_info_sc : public RpcPacket 
	{

	public:
		mrpc_ranking_save_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::ranking_save_info_sc, tag)
		{
		}
		mrpc_ranking_save_info_sc() : RpcPacket(mpe_rpc_cmd::ranking_save_info_sc)
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

}
