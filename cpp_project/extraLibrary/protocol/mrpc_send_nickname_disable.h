#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_send_nickname_disable_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		bool disable{};

	public:
		mrpc_send_nickname_disable_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::send_nickname_disable_cs, tag)
		{
		}
		mrpc_send_nickname_disable_cs() : RpcPacket(mpe_rpc_cmd::send_nickname_disable_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &disable);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_send_nickname_disable_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_send_nickname_disable_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::send_nickname_disable_sc, tag)
		{
		}
		mrpc_send_nickname_disable_sc() : RpcPacket(mpe_rpc_cmd::send_nickname_disable_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
