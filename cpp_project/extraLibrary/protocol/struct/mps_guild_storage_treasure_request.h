#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_storage_treasure_request 
	{
	public:
		int64_t auction_uid{};
	public:
		int64_t cuid{};
	public:
		std::string member_name{};
	public:
		int32_t price{};

	public:
		mps_guild_storage_treasure_request()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &auction_uid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &member_name);
			protocol::SerializeType(pBuffer, &price);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
