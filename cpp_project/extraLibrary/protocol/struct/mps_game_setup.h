#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_game_setup 
	{
	public:
		uint16_t version{};	// 클라 버전정보
	public:
		uint16_t size{};
	public:
		std::vector<uint8_t> data{};

	public:
		mps_game_setup()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &version);
			protocol::SerializeType(pBuffer, &size);
			protocol::SerializeType(pBuffer, &data);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
