#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_guild_member_look_info 
	{
	public:
		int64_t cuid{};
	public:
		uint16_t customizing_data{};
	public:
		std::vector<int32_t> equip_data{};
	public:
		int32_t reflection_id{};

	public:
		mps_guild_member_look_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &customizing_data);
			protocol::SerializeType(pBuffer, &equip_data);
			protocol::SerializeType(pBuffer, &reflection_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
