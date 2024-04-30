#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_global_governance_context.h"
#include "struct/mps_party_governance_rank.h"
#include "struct/mps_party_governance_rank.h"

namespace mir3d
{
	class mrpc_global_party_governance_rank_cs : public RpcPacket 
	{
	private:
		bool flag_info = false;
		mrpcs_global_governance_context info;
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
		mrpc_global_party_governance_rank_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_party_governance_rank_cs, tag)
		{
		}
		mrpc_global_party_governance_rank_cs() : RpcPacket(mpe_rpc_cmd::global_party_governance_rank_cs)
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
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_global_party_governance_rank_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		mpe_global_party_governance_rank_type type{};
	public:
		uint8_t cur_page{};
	public:
		uint8_t max_page{};
	public:
		std::vector<mps_party_governance_rank> list{};
	private:
		bool flag_myinfo = false;
		mps_party_governance_rank myinfo;
		mps_party_governance_rank* p_myinfo = nullptr;
	public:
		bool has_myinfo() const
		{
			return flag_myinfo;
		}
		mps_party_governance_rank* alloc_myinfo()
		{
			flag_myinfo = true;
			return &myinfo;
		}
		const mps_party_governance_rank* get_myinfo() const
		{
			if (true == flag_myinfo)
			{
				if (nullptr == p_myinfo)
				{
					return &myinfo;
				}
				return p_myinfo;
			}
			return nullptr;
		}
		void set_myinfo(mps_party_governance_rank* in_myinfo)
		{
			if (nullptr == p_myinfo)
			{
				p_myinfo = in_myinfo;
				flag_myinfo = true;
			}
		}

	public:
		mrpc_global_party_governance_rank_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::global_party_governance_rank_sc, tag)
		{
		}
		mrpc_global_party_governance_rank_sc() : RpcPacket(mpe_rpc_cmd::global_party_governance_rank_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &cur_page);
			protocol::SerializeType(pBuffer, &max_page);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &flag_myinfo);
			if (true == flag_myinfo)
			{
				if (nullptr != p_myinfo)
					protocol::SerializeType(pBuffer, p_myinfo);
				else
					protocol::SerializeType(pBuffer, &myinfo);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
