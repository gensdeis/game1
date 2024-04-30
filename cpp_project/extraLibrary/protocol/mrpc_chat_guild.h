#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_chat_guild_cs : public RpcPacket 	// 문파채팅
	{
	public:
		int64_t s_uid{};
	public:
		int32_t s_tid{};
	public:
		std::string s_nickname{};
	public:
		std::string message{};
	public:
		int64_t guildid{};

	public:
		mrpc_chat_guild_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::chat_guild_cs, tag)
		{
		}
		mrpc_chat_guild_cs() : RpcPacket(mpe_rpc_cmd::chat_guild_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &s_uid);
			protocol::SerializeType(pBuffer, &s_tid);
			protocol::SerializeType(pBuffer, &s_nickname);
			protocol::SerializeType(pBuffer, &message);
			protocol::SerializeType(pBuffer, &guildid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_chat_guild_sc : public RpcPacket 	// 문파채팅
	{
	public:
		int64_t s_uid{};
	public:
		int32_t s_tid{};
	public:
		std::string s_nickname{};
	public:
		std::vector<int64_t> list_cuid{};
	public:
		std::string message{};
	public:
		int64_t guildid{};

	public:
		mrpc_chat_guild_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::chat_guild_sc, tag)
		{
		}
		mrpc_chat_guild_sc() : RpcPacket(mpe_rpc_cmd::chat_guild_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &s_uid);
			protocol::SerializeType(pBuffer, &s_tid);
			protocol::SerializeType(pBuffer, &s_nickname);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &message);
			protocol::SerializeType(pBuffer, &guildid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
