#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_guild_context.h"
#include "struct/mps_ranking_history.h"

namespace mir3d
{
	class mrpc_guild_leave_cs : public RpcPacket 
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
		mrpc_guild_leave_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_leave_cs, tag)
		{
		}
		mrpc_guild_leave_cs() : RpcPacket(mpe_rpc_cmd::guild_leave_cs)
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

	class mrpc_guild_leave_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		mpe_error error{};
	public:
		int64_t next_available_join_time{};	// // 다음 문파 가입 가능 시간
	private:
		bool flag_ranking_info = false;
		mps_ranking_history ranking_info;	// 문파랭킹 보상 제거를 위한 정보
		mps_ranking_history* p_ranking_info = nullptr;
	public:
		bool has_ranking_info() const
		{
			return flag_ranking_info;
		}
		mps_ranking_history* alloc_ranking_info()
		{
			flag_ranking_info = true;
			return &ranking_info;
		}
		const mps_ranking_history* get_ranking_info() const
		{
			if (true == flag_ranking_info)
			{
				if (nullptr == p_ranking_info)
				{
					return &ranking_info;
				}
				return p_ranking_info;
			}
			return nullptr;
		}
		void set_ranking_info(mps_ranking_history* in_ranking_info)
		{
			if (nullptr == p_ranking_info)
			{
				p_ranking_info = in_ranking_info;
				flag_ranking_info = true;
			}
		}

	public:
		mrpc_guild_leave_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_leave_sc, tag)
		{
		}
		mrpc_guild_leave_sc() : RpcPacket(mpe_rpc_cmd::guild_leave_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &error);
			protocol::SerializeType(pBuffer, &next_available_join_time);
			protocol::SerializeType(pBuffer, &flag_ranking_info);
			if (true == flag_ranking_info)
			{
				if (nullptr != p_ranking_info)
					protocol::SerializeType(pBuffer, p_ranking_info);
				else
					protocol::SerializeType(pBuffer, &ranking_info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
