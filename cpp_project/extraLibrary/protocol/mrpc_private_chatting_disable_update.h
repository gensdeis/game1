#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_private_chatting_disable_update_cs : public RpcPacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		bool disable{};

	public:
		mrpc_private_chatting_disable_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::private_chatting_disable_update_cs, tag)
		{
		}
		mrpc_private_chatting_disable_update_cs() : RpcPacket(mpe_rpc_cmd::private_chatting_disable_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &disable);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_private_chatting_disable_update_sc : public RpcPacket 
	{

	public:
		mrpc_private_chatting_disable_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::private_chatting_disable_update_sc, tag)
		{
		}
		mrpc_private_chatting_disable_update_sc() : RpcPacket(mpe_rpc_cmd::private_chatting_disable_update_sc)
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
