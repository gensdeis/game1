#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_game_logout_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		std::string username{};

	public:
		mrpc_game_logout_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::game_logout_cs, tag)
		{
		}
		mrpc_game_logout_cs() : RpcPacket(mpe_rpc_cmd::game_logout_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &username);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_game_logout_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_game_logout_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::game_logout_sc, tag)
		{
		}
		mrpc_game_logout_sc() : RpcPacket(mpe_rpc_cmd::game_logout_sc)
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
