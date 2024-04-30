#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_guild_shipwar_prepare_request_cs : public RpcPacket 
	{
	public:
		int64_t guid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t tid{};
	public:
		int64_t key{};

	public:
		mrpc_guild_shipwar_prepare_request_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_shipwar_prepare_request_cs, tag)
		{
		}
		mrpc_guild_shipwar_prepare_request_cs() : RpcPacket(mpe_rpc_cmd::guild_shipwar_prepare_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_shipwar_prepare_request_sc : public RpcPacket 
	{
	public:
		int64_t indun_uid{};
	public:
		int32_t index{};	// indun server index
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		int64_t guid{};
	public:
		int32_t tid{};
	public:
		int64_t key{};

	public:
		mrpc_guild_shipwar_prepare_request_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_shipwar_prepare_request_sc, tag)
		{
		}
		mrpc_guild_shipwar_prepare_request_sc() : RpcPacket(mpe_rpc_cmd::guild_shipwar_prepare_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
