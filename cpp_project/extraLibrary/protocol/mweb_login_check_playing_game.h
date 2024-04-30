#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_server_info.h"

namespace mir3d
{
	class mweb_login_check_playing_game_cs : public WebBasePacket 	// (gate에서 삭제)
	{
	public:
		std::string username{};

	public:
		mweb_login_check_playing_game_cs() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &username);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mweb_login_check_playing_game_sc : public WebBasePacket 	// (gate에서 삭제)
	{
	public:
		bool is_playing{};
	public:
		std::string lobby_url{};
	public:
		std::string cashshop_url{};
	public:
		std::vector<mps_server_info> list_gate{};
	public:
		int64_t last_cuid{};
	public:
		int32_t result{};

	public:
		mweb_login_check_playing_game_sc() : WebBasePacket()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			WebBasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &is_playing);
			protocol::SerializeType(pBuffer, &lobby_url);
			protocol::SerializeType(pBuffer, &cashshop_url);
			protocol::SerializeType(pBuffer, &list_gate);
			protocol::SerializeType(pBuffer, &last_cuid);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			WebBasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
