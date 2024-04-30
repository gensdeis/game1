#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_guild_shipwar_league_update_cs : public RpcPacket 
	{
	public:
		int64_t guid{};
	public:
		std::string guild_name{};
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t score{};
	public:
		int32_t gid{};

	public:
		mrpc_gm_guild_shipwar_league_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_guild_shipwar_league_update_cs, tag)
		{
		}
		mrpc_gm_guild_shipwar_league_update_cs() : RpcPacket(mpe_rpc_cmd::gm_guild_shipwar_league_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &score);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_guild_shipwar_league_update_sc : public RpcPacket 
	{

	public:
		mrpc_gm_guild_shipwar_league_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_guild_shipwar_league_update_sc, tag)
		{
		}
		mrpc_gm_guild_shipwar_league_update_sc() : RpcPacket(mpe_rpc_cmd::gm_guild_shipwar_league_update_sc)
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
