#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_avatar_slot_set_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int32_t avatar_id{};
	public:
		mpe_avatar_pos pos{};
	public:
		int32_t release_avatar{};
	public:
		mpe_avatar_pos release_pos{};

	public:
		mrpc_avatar_slot_set_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::avatar_slot_set_cs, tag)
		{
		}
		mrpc_avatar_slot_set_cs() : RpcPacket(mpe_rpc_cmd::avatar_slot_set_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &avatar_id);
			protocol::SerializeEnum(pBuffer, &pos);
			protocol::SerializeType(pBuffer, &release_avatar);
			protocol::SerializeEnum(pBuffer, &release_pos);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_avatar_slot_set_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_avatar_slot_set_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::avatar_slot_set_sc, tag)
		{
		}
		mrpc_avatar_slot_set_sc() : RpcPacket(mpe_rpc_cmd::avatar_slot_set_sc)
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
