#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_game_duplicate_login_cs : public RpcPacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t access_token{};
	public:
		int32_t type{};	// 1 : db 2 : game 3 : world indun

	public:
		mrpc_game_duplicate_login_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::game_duplicate_login_cs, tag)
		{
		}
		mrpc_game_duplicate_login_cs() : RpcPacket(mpe_rpc_cmd::game_duplicate_login_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_game_duplicate_login_sc : public RpcPacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t access_token{};
	public:
		int32_t type{};	// 1 : db 2 : game 3 : world indun

	public:
		mrpc_game_duplicate_login_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::game_duplicate_login_sc, tag)
		{
		}
		mrpc_game_duplicate_login_sc() : RpcPacket(mpe_rpc_cmd::game_duplicate_login_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &access_token);
			protocol::SerializeType(pBuffer, &type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
