#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_character_ability_stat 
	{
	public:
		int32_t lv{};
	public:
		int32_t exp{};

	public:
		mps_character_ability_stat()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &lv);
			protocol::SerializeType(pBuffer, &exp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
