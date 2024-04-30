#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_search_custom_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::string guild_name{};

	public:
		mrpc_guild_search_custom_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_search_custom_cs, tag)
		{
		}
		mrpc_guild_search_custom_cs() : RpcPacket(mpe_rpc_cmd::guild_search_custom_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guild_name);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_search_custom_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		std::string guild_name{};
	public:
		std::string master_name{};
	public:
		int32_t member_count{};
	public:
		int32_t master_level{};
	public:
		int32_t max_member_count{};
	public:
		uint8_t master_class{};
	public:
		int32_t master_expert_level{};	// "전직레벨"

	public:
		mrpc_guild_search_custom_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_search_custom_sc, tag)
		{
		}
		mrpc_guild_search_custom_sc() : RpcPacket(mpe_rpc_cmd::guild_search_custom_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &master_name);
			protocol::SerializeType(pBuffer, &member_count);
			protocol::SerializeType(pBuffer, &master_level);
			protocol::SerializeType(pBuffer, &max_member_count);
			protocol::SerializeType(pBuffer, &master_class);
			protocol::SerializeType(pBuffer, &master_expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
