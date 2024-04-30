#pragma once
#include <vector>
#include <string>
#include "mps_lobby_character.h"

namespace mir3d
{
	class mps_lobby_player 
	{
	public:
		int64_t last_cuid{};
	public:
		std::vector<int64_t> list_cuid{};
	public:
		std::vector<int64_t> list_select_cuid{};
	public:
		std::vector<mps_lobby_character> list_character{};

	public:
		mps_lobby_player()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &last_cuid);
			protocol::SerializeType(pBuffer, &list_cuid);
			protocol::SerializeType(pBuffer, &list_select_cuid);
			protocol::SerializeType(pBuffer, &list_character);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
