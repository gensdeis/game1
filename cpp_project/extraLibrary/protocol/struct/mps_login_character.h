#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_login_character 
	{
	public:
		int32_t gid{};
	public:
		int32_t old_gid{};
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		int32_t id{};
	public:
		int32_t level{};
	public:
		int32_t lasttime{};
	public:
		uint8_t is_delete{};
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_login_character()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &old_gid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &lasttime);
			protocol::SerializeType(pBuffer, &is_delete);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
