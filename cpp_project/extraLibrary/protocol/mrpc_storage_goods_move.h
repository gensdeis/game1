#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_storage_move_goods.h"

namespace mir3d
{
	class mrpc_storage_goods_move_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		std::vector<mps_storage_move_goods> info{};

	public:
		mrpc_storage_goods_move_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::storage_goods_move_cs, tag)
		{
		}
		mrpc_storage_goods_move_cs() : RpcPacket(mpe_rpc_cmd::storage_goods_move_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_storage_goods_move_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_storage_goods_move_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::storage_goods_move_sc, tag)
		{
		}
		mrpc_storage_goods_move_sc() : RpcPacket(mpe_rpc_cmd::storage_goods_move_sc)
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
