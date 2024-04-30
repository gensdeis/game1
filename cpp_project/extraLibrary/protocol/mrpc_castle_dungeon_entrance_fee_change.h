#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_castle_dungeon_entrance_fee_change_cs : public RpcPacket 	// 세율 변경
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t guid{};
	public:
		mpe_siege_castle_type castle_type{};	// 변경할 성 type
	public:
		int32_t entrance_fee{};

	public:
		mrpc_castle_dungeon_entrance_fee_change_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_dungeon_entrance_fee_change_cs, tag)
		{
		}
		mrpc_castle_dungeon_entrance_fee_change_cs() : RpcPacket(mpe_rpc_cmd::castle_dungeon_entrance_fee_change_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &entrance_fee);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_castle_dungeon_entrance_fee_change_sc : public RpcPacket 	// 세율 변경
	{
	public:
		int64_t key{};
	public:
		mpe_siege_castle_type castle_type{};	// 변경할 성 type
	public:
		int32_t entrance_fee{};
	public:
		int64_t aplly_time{};	// 적용날짜

	public:
		mrpc_castle_dungeon_entrance_fee_change_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_dungeon_entrance_fee_change_sc, tag)
		{
		}
		mrpc_castle_dungeon_entrance_fee_change_sc() : RpcPacket(mpe_rpc_cmd::castle_dungeon_entrance_fee_change_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &entrance_fee);
			protocol::SerializeType(pBuffer, &aplly_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
