#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_guild_context.h"

namespace mir3d
{
	class mrpc_guild_respond_surrender_cs : public RpcPacket 
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
		mrpc_guild_respond_surrender_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_respond_surrender_cs, tag)
		{
		}
		mrpc_guild_respond_surrender_cs() : RpcPacket(mpe_rpc_cmd::guild_respond_surrender_cs)
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

	class mrpc_guild_respond_surrender_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t target_guid{};
	public:
		std::string target_guild_name{};
	public:
		bool accept{};
	public:
		int32_t reject_count{};
	public:
		int64_t target_guild_master_cuid{};
	public:
		int64_t negotiation_gold{};
	public:
		int64_t next_available_start_time{};

	public:
		mrpc_guild_respond_surrender_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_respond_surrender_sc, tag)
		{
		}
		mrpc_guild_respond_surrender_sc() : RpcPacket(mpe_rpc_cmd::guild_respond_surrender_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &target_guid);
			protocol::SerializeType(pBuffer, &target_guild_name);
			protocol::SerializeType(pBuffer, &accept);
			protocol::SerializeType(pBuffer, &reject_count);
			protocol::SerializeType(pBuffer, &target_guild_master_cuid);
			protocol::SerializeType(pBuffer, &negotiation_gold);
			protocol::SerializeType(pBuffer, &next_available_start_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
