#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_cash_limit_product_noti_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		std::string username{};

	public:
		mrpc_cash_limit_product_noti_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cash_limit_product_noti_cs, tag)
		{
		}
		mrpc_cash_limit_product_noti_cs() : RpcPacket(mpe_rpc_cmd::cash_limit_product_noti_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &username);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_cash_limit_product_noti_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t last_logout{};

	public:
		mrpc_cash_limit_product_noti_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::cash_limit_product_noti_sc, tag)
		{
		}
		mrpc_cash_limit_product_noti_sc() : RpcPacket(mpe_rpc_cmd::cash_limit_product_noti_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &last_logout);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
