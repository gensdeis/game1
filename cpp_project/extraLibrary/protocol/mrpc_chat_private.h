#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_chat_private_cs : public RpcPacket 	// rpc개인채팅
	{
	public:
		int64_t s_uid{};
	public:
		int64_t t_uid{};
	public:
		std::string s_nickname{};
	public:
		std::string t_nickname{};
	public:
		std::string message{};

	public:
		mrpc_chat_private_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::chat_private_cs, tag)
		{
		}
		mrpc_chat_private_cs() : RpcPacket(mpe_rpc_cmd::chat_private_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &s_uid);
			protocol::SerializeType(pBuffer, &t_uid);
			protocol::SerializeType(pBuffer, &s_nickname);
			protocol::SerializeType(pBuffer, &t_nickname);
			protocol::SerializeType(pBuffer, &message);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_chat_private_sc : public RpcPacket 	// rpc개인채팅
	{
	public:
		int64_t s_uid{};
	public:
		int64_t t_uid{};
	public:
		std::string s_nickname{};
	public:
		std::string t_nickname{};
	public:
		std::string message{};

	public:
		mrpc_chat_private_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::chat_private_sc, tag)
		{
		}
		mrpc_chat_private_sc() : RpcPacket(mpe_rpc_cmd::chat_private_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &s_uid);
			protocol::SerializeType(pBuffer, &t_uid);
			protocol::SerializeType(pBuffer, &s_nickname);
			protocol::SerializeType(pBuffer, &t_nickname);
			protocol::SerializeType(pBuffer, &message);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
