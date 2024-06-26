﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_siege_warfare_alliance_info.h"

namespace mir3d
{
	class mrpc_gate_siege_warfare_guild_search_cs : public RpcPacket 	// 공성문파검색
	{
	public:
		int64_t key{};
	public:
		std::string search_name{};	// 검색 문파 이름
	public:
		int64_t siege_guid{};	// 공성입찰 1위 문파 guid

	public:
		mrpc_gate_siege_warfare_guild_search_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_siege_warfare_guild_search_cs, tag)
		{
		}
		mrpc_gate_siege_warfare_guild_search_cs() : RpcPacket(mpe_rpc_cmd::gate_siege_warfare_guild_search_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &search_name);
			protocol::SerializeType(pBuffer, &siege_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_siege_warfare_guild_search_sc : public RpcPacket 	// 공성문파검색
	{
	public:
		int64_t key{};
	private:
		bool flag_siege_guild = false;
		mps_siege_warfare_alliance_info siege_guild;	// 공성문파
		mps_siege_warfare_alliance_info* p_siege_guild = nullptr;
	public:
		bool has_siege_guild() const
		{
			return flag_siege_guild;
		}
		mps_siege_warfare_alliance_info* alloc_siege_guild()
		{
			flag_siege_guild = true;
			return &siege_guild;
		}
		const mps_siege_warfare_alliance_info* get_siege_guild() const
		{
			if (true == flag_siege_guild)
			{
				if (nullptr == p_siege_guild)
				{
					return &siege_guild;
				}
				return p_siege_guild;
			}
			return nullptr;
		}
		void set_siege_guild(mps_siege_warfare_alliance_info* in_siege_guild)
		{
			if (nullptr == p_siege_guild)
			{
				p_siege_guild = in_siege_guild;
				flag_siege_guild = true;
			}
		}

	public:
		mrpc_gate_siege_warfare_guild_search_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_siege_warfare_guild_search_sc, tag)
		{
		}
		mrpc_gate_siege_warfare_guild_search_sc() : RpcPacket(mpe_rpc_cmd::gate_siege_warfare_guild_search_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &flag_siege_guild);
			if (true == flag_siege_guild)
			{
				if (nullptr != p_siege_guild)
					protocol::SerializeType(pBuffer, p_siege_guild);
				else
					protocol::SerializeType(pBuffer, &siege_guild);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
