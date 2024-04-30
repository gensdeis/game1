#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_global_governance_context.h"
#include "struct/mrpcs_global_governance_context.h"

namespace mir3d
{
	class mrpc_global_party_governance_token_history_cs : public RpcPacket 	// 파티 거버넌스 토큰 히스토리 정보전달
	{
	private:
		bool flag_info = false;
		mrpcs_global_governance_context info;	// 거버넌스 정보
		mrpcs_global_governance_context* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_global_governance_context* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_global_governance_context* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mrpcs_global_governance_context* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		mpe_coin_staking_type staking_type{};	// 스테이킹 타입(1:투표/2:회수)
	public:
		bool is_success{};	// 스테이킹 및 언스테이킹 성공유무

	public:
		mrpc_global_party_governance_token_history_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_party_governance_token_history_cs, tag)
		{
		}
		mrpc_global_party_governance_token_history_cs() : RpcPacket(mpe_rpc_cmd::global_party_governance_token_history_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeEnum(pBuffer, &staking_type);
			protocol::SerializeType(pBuffer, &is_success);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_global_party_governance_token_history_sc : public RpcPacket 	// 파티 거버넌스 토큰 히스토리 정보전달
	{
	private:
		bool flag_info = false;
		mrpcs_global_governance_context info;	// 거버넌스 정보
		mrpcs_global_governance_context* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_global_governance_context* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_global_governance_context* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mrpcs_global_governance_context* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}
	public:
		mpe_coin_staking_type staking_type{};	// 스테이킹 타입(1:투표/2:회수)
	public:
		bool is_success{};	// 스테이킹 및 언스테이킹 성공유무

	public:
		mrpc_global_party_governance_token_history_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_party_governance_token_history_sc, tag)
		{
		}
		mrpc_global_party_governance_token_history_sc() : RpcPacket(mpe_rpc_cmd::global_party_governance_token_history_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
			protocol::SerializeEnum(pBuffer, &staking_type);
			protocol::SerializeType(pBuffer, &is_success);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
