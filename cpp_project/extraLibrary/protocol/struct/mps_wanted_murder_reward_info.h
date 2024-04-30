#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_wanted_murder_reward_info 
	{
	public:
		int64_t ruid{};
	public:
		int64_t reward_cuid{};
	public:
		int64_t target_cuid{};
	public:
		int32_t level{};
	public:
		int32_t id{};
	public:
		std::string nickname{};
	public:
		int64_t expire_date{};
	public:
		int32_t reward_value{};
	public:
		std::vector<int32_t> list_shop_id{};
	public:
		bool reward_complete{};

	public:
		mps_wanted_murder_reward_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &ruid);
			protocol::SerializeType(pBuffer, &reward_cuid);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &expire_date);
			protocol::SerializeType(pBuffer, &reward_value);
			protocol::SerializeType(pBuffer, &list_shop_id);
			protocol::SerializeType(pBuffer, &reward_complete);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
