#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_npc_buy_count.h"

namespace mir3d
{
	class mrpc_npc_shop_open_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int32_t shop_group_id{};

	public:
		mrpc_npc_shop_open_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::npc_shop_open_cs, tag)
		{
		}
		mrpc_npc_shop_open_cs() : RpcPacket(mpe_rpc_cmd::npc_shop_open_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &shop_group_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_npc_shop_open_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_npc_buy_count> list{};
	public:
		int32_t shop_group_id{};

	public:
		mrpc_npc_shop_open_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::npc_shop_open_sc, tag)
		{
		}
		mrpc_npc_shop_open_sc() : RpcPacket(mpe_rpc_cmd::npc_shop_open_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &list);
			protocol::SerializeType(pBuffer, &shop_group_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
