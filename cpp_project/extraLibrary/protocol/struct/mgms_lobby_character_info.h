#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mgms_lobby_character_info 
	{
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		int32_t tid{};
	public:
		int32_t level{};
	public:
		int32_t zone_id{};

	public:
		mgms_lobby_character_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &zone_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
