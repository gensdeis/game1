#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_castle_owner_change_mark_cs : public RpcPacket 
	{

	public:
		mrpc_castle_owner_change_mark_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_owner_change_mark_cs, tag)
		{
		}
		mrpc_castle_owner_change_mark_cs() : RpcPacket(mpe_rpc_cmd::castle_owner_change_mark_cs)
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

	class mrpc_castle_owner_change_mark_sc : public RpcPacket 
	{
	public:
		mpe_siege_castle_type castle_type{};
	public:
		std::vector<uint8_t> guild_mark{};

	public:
		mrpc_castle_owner_change_mark_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::castle_owner_change_mark_sc, tag)
		{
		}
		mrpc_castle_owner_change_mark_sc() : RpcPacket(mpe_rpc_cmd::castle_owner_change_mark_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &guild_mark);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
