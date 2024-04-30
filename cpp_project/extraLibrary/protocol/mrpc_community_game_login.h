#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_community_game_login_cs : public RpcPacket 
	{

	public:
		mrpc_community_game_login_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_game_login_cs, tag)
		{
		}
		mrpc_community_game_login_cs() : RpcPacket(mpe_rpc_cmd::community_game_login_cs)
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

	class mrpc_community_game_login_sc : public RpcPacket 
	{
	public:
		int64_t gate_session_id{};
	public:
		int32_t gid{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		bool logoff_world{};
	public:
		int64_t puid{};
	public:
		int64_t guid{};
	public:
		int32_t level{};
	public:
		bool private_chatting_disable{};
	public:
		mrpce_server_type server_type{};
	public:
		mrpce_server_type sender_server_type{};
	public:
		bool reconnect{};
	public:
		int64_t channel_uid{};
	public:
		int32_t team_index{};
	public:
		int32_t expert_level{};

	public:
		mrpc_community_game_login_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_game_login_sc, tag)
		{
		}
		mrpc_community_game_login_sc() : RpcPacket(mpe_rpc_cmd::community_game_login_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gate_session_id);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &logoff_world);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &private_chatting_disable);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeEnum(pBuffer, &sender_server_type);
			protocol::SerializeType(pBuffer, &reconnect);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &team_index);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
