#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_subscription_del_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int32_t subscription_id{};

	public:
		mrpc_subscription_del_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::subscription_del_cs, tag)
		{
		}
		mrpc_subscription_del_cs() : RpcPacket(mpe_rpc_cmd::subscription_del_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &subscription_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_subscription_del_sc : public RpcPacket 
	{

	public:
		mrpc_subscription_del_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::subscription_del_sc, tag)
		{
		}
		mrpc_subscription_del_sc() : RpcPacket(mpe_rpc_cmd::subscription_del_sc)
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
