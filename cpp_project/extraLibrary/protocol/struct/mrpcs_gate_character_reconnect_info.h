#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_gate_character_reconnect_info 
	{
	public:
		std::string nickname{};
	public:
		mrpce_server_type server_type{};
	public:
		int64_t cuid{};
	public:
		int32_t level{};
	public:
		int64_t channel_uid{};
	public:
		int32_t team_index{};
	public:
		int64_t puid{};
	public:
		int64_t guid{};
	public:
		bool private_chatting_disable{};

	public:
		mrpcs_gate_character_reconnect_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &team_index);
			protocol::SerializeType(pBuffer, &puid);
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &private_chatting_disable);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
