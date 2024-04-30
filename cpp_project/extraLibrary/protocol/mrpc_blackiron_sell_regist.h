#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_blackiron_sell_regist_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t guid{};
	public:
		int64_t cuid{};
	public:
		int32_t sell_count{};
	public:
		int32_t sell_price{};

	public:
		mrpc_blackiron_sell_regist_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blackiron_sell_regist_cs, tag)
		{
		}
		mrpc_blackiron_sell_regist_cs() : RpcPacket(mpe_rpc_cmd::blackiron_sell_regist_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &sell_count);
			protocol::SerializeType(pBuffer, &sell_price);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_blackiron_sell_regist_sc : public RpcPacket 
	{
	public:
		int64_t key{};	// 문주
	public:
		int32_t guild_blackiron_count{};	// 남은 문파흑철

	public:
		mrpc_blackiron_sell_regist_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::blackiron_sell_regist_sc, tag)
		{
		}
		mrpc_blackiron_sell_regist_sc() : RpcPacket(mpe_rpc_cmd::blackiron_sell_regist_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &guild_blackiron_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
