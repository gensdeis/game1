#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_token_history_item_select_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t huid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};

	public:
		mrpc_token_history_item_select_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::token_history_item_select_cs, tag)
		{
		}
		mrpc_token_history_item_select_cs() : RpcPacket(mpe_rpc_cmd::token_history_item_select_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &huid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_token_history_item_select_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t huid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t tid{};
	public:
		int32_t count{};

	public:
		mrpc_token_history_item_select_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::token_history_item_select_sc, tag)
		{
		}
		mrpc_token_history_item_select_sc() : RpcPacket(mpe_rpc_cmd::token_history_item_select_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &huid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
