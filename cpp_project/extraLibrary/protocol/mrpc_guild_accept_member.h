#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_guild_context.h"

namespace mir3d
{
	class mrpc_guild_accept_member_cs : public RpcPacket 
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
		mrpc_guild_accept_member_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_accept_member_cs, tag)
		{
		}
		mrpc_guild_accept_member_cs() : RpcPacket(mpe_rpc_cmd::guild_accept_member_cs)
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

	class mrpc_guild_accept_member_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		bool accept{};
	public:
		int64_t target_uid{};

	public:
		mrpc_guild_accept_member_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_accept_member_sc, tag)
		{
		}
		mrpc_guild_accept_member_sc() : RpcPacket(mpe_rpc_cmd::guild_accept_member_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &accept);
			protocol::SerializeType(pBuffer, &target_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
