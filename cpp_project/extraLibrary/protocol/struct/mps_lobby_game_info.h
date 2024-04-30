#pragma once
#include <vector>
#include <string>
#include "mps_server_info.h"

namespace mir3d
{
	class mps_lobby_game_info 
	{
	public:
		int32_t awaiter_count{};
	public:
		bool quicklogin{};
	public:
		std::vector<mps_server_info> info{};	// mpe_gameserver_type
	public:
		int32_t dungeon_id{};	// 인던 일 경우 dungeon_control_table id 값

	public:
		mps_lobby_game_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &awaiter_count);
			protocol::SerializeType(pBuffer, &quicklogin);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &dungeon_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
