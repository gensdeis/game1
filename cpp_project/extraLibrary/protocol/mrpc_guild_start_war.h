#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_guild_context.h"
#include "struct/mps_guild_war.h"

namespace mir3d
{
	class mrpc_guild_start_war_cs : public RpcPacket 
	{
	private:
		bool flag_guild_context = false;
		mrpcs_guild_context guild_context;
		mrpcs_guild_context* p_guild_context = nullptr;
	public:
		bool has_guild_context() const
		{
			return flag_guild_context;
		}
		mrpcs_guild_context* alloc_guild_context()
		{
			flag_guild_context = true;
			return &guild_context;
		}
		const mrpcs_guild_context* get_guild_context() const
		{
			if (true == flag_guild_context)
			{
				if (nullptr == p_guild_context)
				{
					return &guild_context;
				}
				return p_guild_context;
			}
			return nullptr;
		}
		void set_guild_context(mrpcs_guild_context* in_guild_context)
		{
			if (nullptr == p_guild_context)
			{
				p_guild_context = in_guild_context;
				flag_guild_context = true;
			}
		}

	public:
		mrpc_guild_start_war_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_start_war_cs, tag)
		{
		}
		mrpc_guild_start_war_cs() : RpcPacket(mpe_rpc_cmd::guild_start_war_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_guild_context);
			if (true == flag_guild_context)
			{
				if (nullptr != p_guild_context)
					protocol::SerializeType(pBuffer, p_guild_context);
				else
					protocol::SerializeType(pBuffer, &guild_context);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_start_war_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_war = false;
		mps_guild_war war;
		mps_guild_war* p_war = nullptr;
	public:
		bool has_war() const
		{
			return flag_war;
		}
		mps_guild_war* alloc_war()
		{
			flag_war = true;
			return &war;
		}
		const mps_guild_war* get_war() const
		{
			if (true == flag_war)
			{
				if (nullptr == p_war)
				{
					return &war;
				}
				return p_war;
			}
			return nullptr;
		}
		void set_war(mps_guild_war* in_war)
		{
			if (nullptr == p_war)
			{
				p_war = in_war;
				flag_war = true;
			}
		}

	public:
		mrpc_guild_start_war_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_start_war_sc, tag)
		{
		}
		mrpc_guild_start_war_sc() : RpcPacket(mpe_rpc_cmd::guild_start_war_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_war);
			if (true == flag_war)
			{
				if (nullptr != p_war)
					protocol::SerializeType(pBuffer, p_war);
				else
					protocol::SerializeType(pBuffer, &war);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
