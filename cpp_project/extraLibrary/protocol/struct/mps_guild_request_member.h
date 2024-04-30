#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_request_member 
	{
	public:
		int64_t cuid{};
	public:
		std::string nickname{};
	public:
		int32_t class_id{};
	public:
		int32_t level{};
	public:
		int64_t request_expire_time{};
	public:
		int32_t expert_level{};	// "전직레벨"

	public:
		mps_guild_request_member()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &class_id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &request_expire_time);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
