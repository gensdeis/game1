#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_character_situation.h"

namespace mir3d
{
	class mrpc_guild_shipwar_calculate_cs : public RpcPacket 
	{
	public:
		int64_t guid{};
	public:
		int32_t score{};
	public:
		bool win{};
	public:
		std::string guild_name{};
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		std::vector<mps_character_situation> guild_member{};
	public:
		int32_t gid{};

	public:
		mrpc_guild_shipwar_calculate_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_shipwar_calculate_cs, tag)
		{
		}
		mrpc_guild_shipwar_calculate_cs() : RpcPacket(mpe_rpc_cmd::guild_shipwar_calculate_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &score);
			protocol::SerializeType(pBuffer, &win);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &guild_member);
			protocol::SerializeType(pBuffer, &gid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_shipwar_calculate_sc : public RpcPacket 
	{

	public:
		mrpc_guild_shipwar_calculate_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_shipwar_calculate_sc, tag)
		{
		}
		mrpc_guild_shipwar_calculate_sc() : RpcPacket(mpe_rpc_cmd::guild_shipwar_calculate_sc)
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
