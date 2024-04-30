#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_guild_goods.h"

namespace mir3d
{
	class mrpc_guild_goods_exchange_cs : public RpcPacket 
	{
	public:
		int64_t guid{};
	public:
		int64_t cuid{};
	public:
		int32_t goods_type{};
	public:
		int32_t goods_count{};

	public:
		mrpc_guild_goods_exchange_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_goods_exchange_cs, tag)
		{
		}
		mrpc_guild_goods_exchange_cs() : RpcPacket(mpe_rpc_cmd::guild_goods_exchange_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &goods_type);
			protocol::SerializeType(pBuffer, &goods_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_goods_exchange_sc : public RpcPacket 
	{
	public:
		mpe_error result{};
	public:
		int64_t guid{};
	public:
		int64_t cuid{};
	public:
		std::vector<mps_guild_goods> list_guild_goods{};

	public:
		mrpc_guild_goods_exchange_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_goods_exchange_sc, tag)
		{
		}
		mrpc_guild_goods_exchange_sc() : RpcPacket(mpe_rpc_cmd::guild_goods_exchange_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &list_guild_goods);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
