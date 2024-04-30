#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_player_game_login_cs : public RpcPacket 
	{
	public:
		int64_t auid{};

	public:
		mrpc_player_game_login_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::player_game_login_cs, tag)
		{
		}
		mrpc_player_game_login_cs() : RpcPacket(mpe_rpc_cmd::player_game_login_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_player_game_login_sc : public RpcPacket 
	{
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		int64_t indun_uid{};	// 인던에서 접속종료했던 유저 정리 위해서
	public:
		bool admin_kick{};	// gm_kick
	public:
		mrpce_server_type server_type{};
	public:
		int32_t server_index{};

	public:
		mrpc_player_game_login_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::player_game_login_sc, tag)
		{
		}
		mrpc_player_game_login_sc() : RpcPacket(mpe_rpc_cmd::player_game_login_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &indun_uid);
			protocol::SerializeType(pBuffer, &admin_kick);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &server_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
