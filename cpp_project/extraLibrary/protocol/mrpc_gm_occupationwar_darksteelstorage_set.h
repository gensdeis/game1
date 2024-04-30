#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_occupationwar_darksteelstorage_set_cs : public RpcPacket 
	{

	public:
		mrpc_gm_occupationwar_darksteelstorage_set_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_occupationwar_darksteelstorage_set_cs, tag)
		{
		}
		mrpc_gm_occupationwar_darksteelstorage_set_cs() : RpcPacket(mpe_rpc_cmd::gm_occupationwar_darksteelstorage_set_cs)
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

	class mrpc_gm_occupationwar_darksteelstorage_set_sc : public RpcPacket 
	{
	public:
		mpe_occupationwar_map_type map_type{};
	public:
		int64_t darksteel{};
	public:
		int32_t set_type{};	// 1 - 지급, 2 - 차감

	public:
		mrpc_gm_occupationwar_darksteelstorage_set_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_occupationwar_darksteelstorage_set_sc, tag)
		{
		}
		mrpc_gm_occupationwar_darksteelstorage_set_sc() : RpcPacket(mpe_rpc_cmd::gm_occupationwar_darksteelstorage_set_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &map_type);
			protocol::SerializeType(pBuffer, &darksteel);
			protocol::SerializeType(pBuffer, &set_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
