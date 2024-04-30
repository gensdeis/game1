#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_chat_normal_cs : public RpcPacket 	// 공통채팅
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
		int32_t serverid{};

	public:
		mrpc_chat_normal_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::chat_normal_cs, tag)
		{
		}
		mrpc_chat_normal_cs() : RpcPacket(mpe_rpc_cmd::chat_normal_cs)
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
			protocol::SerializeType(pBuffer, &serverid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_chat_normal_sc : public RpcPacket 	// 공통채팅
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
		mrpc_chat_normal_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::chat_normal_sc, tag)
		{
		}
		mrpc_chat_normal_sc() : RpcPacket(mpe_rpc_cmd::chat_normal_sc)
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
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
