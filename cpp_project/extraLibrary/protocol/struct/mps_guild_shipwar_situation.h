#pragma once
#include <vector>
#include <string>
#include "mps_character_situation.h"
#include "mps_character_situation.h"

namespace mir3d
{
	class mps_guild_shipwar_situation 
	{
	public:
		std::vector<mps_character_situation> guild_member_A{};
	public:
		std::vector<mps_character_situation> guild_member_B{};

	public:
		mps_guild_shipwar_situation()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &guild_member_A);
			protocol::SerializeType(pBuffer, &guild_member_B);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
