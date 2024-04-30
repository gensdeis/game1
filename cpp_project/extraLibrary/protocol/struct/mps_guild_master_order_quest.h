#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_master_order_quest 
	{
	public:
		int32_t quest_tid{};
	public:
		int64_t expire_time{};
	public:
		int32_t current_finish_member_count{};

	public:
		mps_guild_master_order_quest()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &quest_tid);
			protocol::SerializeType(pBuffer, &expire_time);
			protocol::SerializeType(pBuffer, &current_finish_member_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
