#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_field_boss_spawn_cs : public RpcPacket 
	{
	public:
		bool is_dead{};
	public:
		int32_t zone_id{};

	public:
		mrpc_field_boss_spawn_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::field_boss_spawn_cs, tag)
		{
		}
		mrpc_field_boss_spawn_cs() : RpcPacket(mpe_rpc_cmd::field_boss_spawn_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &is_dead);
			protocol::SerializeType(pBuffer, &zone_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_field_boss_spawn_sc : public RpcPacket 
	{
	public:
		int32_t zone_id{};
	public:
		int32_t tid{};
	public:
		int64_t channel_uid{};

	public:
		mrpc_field_boss_spawn_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::field_boss_spawn_sc, tag)
		{
		}
		mrpc_field_boss_spawn_sc() : RpcPacket(mpe_rpc_cmd::field_boss_spawn_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &channel_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
