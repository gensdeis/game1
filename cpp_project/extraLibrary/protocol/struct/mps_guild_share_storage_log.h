#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_share_storage_log 
	{
	public:
		mpe_guild_share_storage_log log_type{};
	public:
		std::string nickname{};
	public:
		int32_t item_tid{};
	public:
		int32_t item_count{};
	public:
		int32_t reg_time{};

	public:
		mps_guild_share_storage_log()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &log_type);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &item_tid);
			protocol::SerializeType(pBuffer, &item_count);
			protocol::SerializeType(pBuffer, &reg_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
