#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_siege_bot_create_cs : public RpcPacket 
	{
	public:
		std::string ip{};
	public:
		int32_t port{};
	public:
		int32_t id{};
	public:
		int64_t indun_uid{};
	public:
		int32_t count{};

	public:
		mrpc_siege_bot_create_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_bot_create_cs, tag)
		{
		}
		mrpc_siege_bot_create_cs() : RpcPacket(mpe_rpc_cmd::siege_bot_create_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ip);
			protocol::SerializeType(pBuffer, &port);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_siege_bot_create_sc : public RpcPacket 
	{

	public:
		mrpc_siege_bot_create_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_bot_create_sc, tag)
		{
		}
		mrpc_siege_bot_create_sc() : RpcPacket(mpe_rpc_cmd::siege_bot_create_sc)
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
