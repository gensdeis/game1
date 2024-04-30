#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_siege_warfare_request_alliance_info 
	{
	public:
		int64_t guid{};
	public:
		std::string name{};
	public:
		int32_t level{};
	public:
		int64_t master_cuid{};
	public:
		std::string master_name{};
	public:
		int32_t member_cnt{};
	public:
		bool is_enemy{};
	public:
		bool accept{};
	public:
		std::vector<uint8_t> guild_mark{};
	public:
		int32_t master_class{};

	public:
		mps_siege_warfare_request_alliance_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &name);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &master_cuid);
			protocol::SerializeType(pBuffer, &master_name);
			protocol::SerializeType(pBuffer, &member_cnt);
			protocol::SerializeType(pBuffer, &is_enemy);
			protocol::SerializeType(pBuffer, &accept);
			protocol::SerializeType(pBuffer, &guild_mark);
			protocol::SerializeType(pBuffer, &master_class);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
