#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_ally_request_info 
	{
	public:
		int64_t recv_guid{};	// "동맹 신청받은 길드 uid."
	public:
		int64_t request_guid{};	// "동맹 신청한 길드 uid"
	public:
		int64_t request_time{};	// "신청한 시간"

	public:
		mps_guild_ally_request_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &recv_guid);
			protocol::SerializeType(pBuffer, &request_guid);
			protocol::SerializeType(pBuffer, &request_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
