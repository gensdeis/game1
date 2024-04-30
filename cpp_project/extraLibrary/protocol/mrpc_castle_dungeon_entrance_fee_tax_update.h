#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_castle_dungeon_entrance_fee_tax_update_cs : public RpcPacket 	// 성관할던전입장료세금
	{
	public:
		int64_t guid{};
	public:
		mpe_siege_castle_type castle_type{};
	public:
		int32_t entrance_fee_tax{};

	public:
		mrpc_castle_dungeon_entrance_fee_tax_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_dungeon_entrance_fee_tax_update_cs, tag)
		{
		}
		mrpc_castle_dungeon_entrance_fee_tax_update_cs() : RpcPacket(mpe_rpc_cmd::castle_dungeon_entrance_fee_tax_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &entrance_fee_tax);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_castle_dungeon_entrance_fee_tax_update_sc : public RpcPacket 	// 성관할던전입장료세금
	{

	public:
		mrpc_castle_dungeon_entrance_fee_tax_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_dungeon_entrance_fee_tax_update_sc, tag)
		{
		}
		mrpc_castle_dungeon_entrance_fee_tax_update_sc() : RpcPacket(mpe_rpc_cmd::castle_dungeon_entrance_fee_tax_update_sc)
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
