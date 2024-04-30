#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_dimension_dungeon_crack_cmd_cs : public RpcPacket 
	{
	public:
		bool is_boss{};	// "보스 차원의틈 true, 일반 false "
	public:
		int64_t _uid{};	// World Game 서버 내 로직을 위한 값으로 World Game Manager에서는 무시 또는 0 할당

	public:
		mrpc_gm_dimension_dungeon_crack_cmd_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_dimension_dungeon_crack_cmd_cs, tag)
		{
		}
		mrpc_gm_dimension_dungeon_crack_cmd_cs() : RpcPacket(mpe_rpc_cmd::gm_dimension_dungeon_crack_cmd_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &is_boss);
			protocol::SerializeType(pBuffer, &_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_dimension_dungeon_crack_cmd_sc : public RpcPacket 
	{
	public:
		bool is_success{};

	public:
		mrpc_gm_dimension_dungeon_crack_cmd_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_dimension_dungeon_crack_cmd_sc, tag)
		{
		}
		mrpc_gm_dimension_dungeon_crack_cmd_sc() : RpcPacket(mpe_rpc_cmd::gm_dimension_dungeon_crack_cmd_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &is_success);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
