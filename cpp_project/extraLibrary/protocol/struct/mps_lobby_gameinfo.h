#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_lobby_gameinfo 
	{
	public:
		int32_t awaiter_count{};
	public:
		bool quicklogin{};
	public:
		std::string board_url{};
	public:
		std::string world_board_url{};
	public:
		std::string global_board_url{};
	public:
		std::string event_url{};
	public:
		std::string server_ip{};
	public:
		uint16_t server_port{};
	public:
		std::string community_ip{};	// 채팅서버 정보
	public:
		uint16_t community_port{};	// 채팅서버 정보
	public:
		int32_t dungeon_id{};	// 인던 일 경우 dungeon_control_table id 값

	public:
		mps_lobby_gameinfo()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &awaiter_count);
			protocol::SerializeType(pBuffer, &quicklogin);
			protocol::SerializeType(pBuffer, &board_url);
			protocol::SerializeType(pBuffer, &world_board_url);
			protocol::SerializeType(pBuffer, &global_board_url);
			protocol::SerializeType(pBuffer, &event_url);
			protocol::SerializeType(pBuffer, &server_ip);
			protocol::SerializeType(pBuffer, &server_port);
			protocol::SerializeType(pBuffer, &community_ip);
			protocol::SerializeType(pBuffer, &community_port);
			protocol::SerializeType(pBuffer, &dungeon_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
