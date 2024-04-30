#pragma once
#include <vector>
#include <string>
#include "mps_player_character.h"

namespace mir3d
{
	class mps_player 
	{
	public:
		int64_t last_cuid{};	// lastplaycharacteruid
	public:
		std::vector<mps_player_character> list_character{};

	public:
		mps_player()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &last_cuid);
			protocol::SerializeType(pBuffer, &list_character);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
