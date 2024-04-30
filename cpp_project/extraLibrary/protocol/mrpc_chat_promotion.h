#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_chat_promotion_cs : public RpcPacket 	// 홍보
	{
	public:
		int32_t p_type{};

	public:
		mrpc_chat_promotion_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::chat_promotion_cs, tag)
		{
		}
		mrpc_chat_promotion_cs() : RpcPacket(mpe_rpc_cmd::chat_promotion_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &p_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_chat_promotion_sc : public RpcPacket 	// 홍보
	{
	public:
		int32_t p_type{};
	public:
		int64_t guildid{};
	public:
		int64_t partyid{};
	public:
		std::string message{};

	public:
		mrpc_chat_promotion_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::chat_promotion_sc, tag)
		{
		}
		mrpc_chat_promotion_sc() : RpcPacket(mpe_rpc_cmd::chat_promotion_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &p_type);
			protocol::SerializeType(pBuffer, &guildid);
			protocol::SerializeType(pBuffer, &partyid);
			protocol::SerializeType(pBuffer, &message);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
