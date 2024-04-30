#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_game_option 
	{
	public:
		uint16_t option_size{};	// 옵션설정크기
	public:
		std::vector<uint8_t> option_data{};	// 옵션설정데이터

	public:
		mps_game_option()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &option_size);
			protocol::SerializeType(pBuffer, &option_data);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
