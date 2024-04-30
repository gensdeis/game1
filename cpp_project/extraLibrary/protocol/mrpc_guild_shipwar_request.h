#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_shipwar_request_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t guid{};
	public:
		int64_t cuid{};
	public:
		bool isJoin{};
	public:
		int32_t gid{};
	public:
		std::string guild_name{};
	public:
		std::vector<uint8_t> guild_mark{};

	public:
		mrpc_guild_shipwar_request_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_shipwar_request_cs, tag)
		{
		}
		mrpc_guild_shipwar_request_cs() : RpcPacket(mpe_rpc_cmd::guild_shipwar_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &isJoin);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &guild_name);
			protocol::SerializeType(pBuffer, &guild_mark);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_shipwar_request_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		mpe_guild_shipwar_state state{};
	public:
		mpe_error result{};

	public:
		mrpc_guild_shipwar_request_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_shipwar_request_sc, tag)
		{
		}
		mrpc_guild_shipwar_request_sc() : RpcPacket(mpe_rpc_cmd::guild_shipwar_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
