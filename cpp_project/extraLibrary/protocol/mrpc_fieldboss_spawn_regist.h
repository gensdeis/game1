#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_fieldboss_spawn_regist_cs : public RpcPacket 
	{
	public:
		int32_t monster_table_id{};
	public:
		int32_t spawn_time{};
	public:
		int32_t zone_id{};
	public:
		int64_t channel_uid{};

	public:
		mrpc_fieldboss_spawn_regist_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::fieldboss_spawn_regist_cs, tag)
		{
		}
		mrpc_fieldboss_spawn_regist_cs() : RpcPacket(mpe_rpc_cmd::fieldboss_spawn_regist_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &monster_table_id);
			protocol::SerializeType(pBuffer, &spawn_time);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &channel_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_fieldboss_spawn_regist_sc : public RpcPacket 
	{
	public:
		int64_t channel_uid{};

	public:
		mrpc_fieldboss_spawn_regist_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::fieldboss_spawn_regist_sc, tag)
		{
		}
		mrpc_fieldboss_spawn_regist_sc() : RpcPacket(mpe_rpc_cmd::fieldboss_spawn_regist_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &channel_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
