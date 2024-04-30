#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_castle_info 	// 길드에서 사용하는 성정보
	{
	public:
		mpe_siege_castle_type castle_type{};	// 성타입
	public:
		int64_t guid{};	// 성주길드

	public:
		mps_guild_castle_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &guid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
