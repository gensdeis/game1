#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_chat_guild_ally_cs : public RpcPacket 	// 문파채팅
	{
	public:
		int64_t s_uid{};	// "발송자cuid"
	public:
		std::string s_nickname{};	// "발송자닉네임"
	public:
		std::string message{};	// "메세지"
	public:
		int64_t ally_guid{};	// "동맹 길드 uid"

	public:
		mrpc_chat_guild_ally_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::chat_guild_ally_cs, tag)
		{
		}
		mrpc_chat_guild_ally_cs() : RpcPacket(mpe_rpc_cmd::chat_guild_ally_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &s_uid);
			protocol::SerializeType(pBuffer, &s_nickname);
			protocol::SerializeType(pBuffer, &message);
			protocol::SerializeType(pBuffer, &ally_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_chat_guild_ally_sc : public RpcPacket 	// 문파채팅
	{
	public:
		int64_t s_uid{};	// "발송자cuid"
	public:
		std::string s_nickname{};	// "발송자닉네임"
	public:
		std::vector<int64_t> list_cuid{};	// "수신받을 유저목록"
	public:
		std::string message{};	// "메세지"
	public:
		int64_t s_guid{};	// "발송자guid"

	public:
		mrpc_chat_guild_ally_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::chat_guild_ally_sc, tag)
		{
		}
		mrpc_chat_guild_ally_sc() : RpcPacket(mpe_rpc_cmd::chat_guild_ally_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &s_uid);
			protocol::SerializeType(pBuffer, &s_nickname);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &message);
			protocol::SerializeType(pBuffer, &s_guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
