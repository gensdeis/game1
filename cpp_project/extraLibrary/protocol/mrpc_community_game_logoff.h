#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_community_game_logoff_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};

	public:
		mrpc_community_game_logoff_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_game_logoff_cs, tag)
		{
		}
		mrpc_community_game_logoff_cs() : RpcPacket(mpe_rpc_cmd::community_game_logoff_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_community_game_logoff_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};

	public:
		mrpc_community_game_logoff_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_game_logoff_sc, tag)
		{
		}
		mrpc_community_game_logoff_sc() : RpcPacket(mpe_rpc_cmd::community_game_logoff_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
