﻿#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_wanted_murder_register_info 
	{
	public:
		int64_t record_id{};
	public:
		int64_t target_cuid{};
	public:
		int32_t level{};
	public:
		int32_t id{};
	public:
		std::string nickname{};
	public:
		int64_t register_cuid{};
	public:
		int32_t reward_value{};
	public:
		int32_t shop_id{};
	public:
		int32_t expire_date{};
	public:
		int32_t expert_level{};

	public:
		mps_wanted_murder_register_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &record_id);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &id);
			protocol::SerializeType(pBuffer, &nickname);
			protocol::SerializeType(pBuffer, &register_cuid);
			protocol::SerializeType(pBuffer, &reward_value);
			protocol::SerializeType(pBuffer, &shop_id);
			protocol::SerializeType(pBuffer, &expire_date);
			protocol::SerializeType(pBuffer, &expert_level);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
