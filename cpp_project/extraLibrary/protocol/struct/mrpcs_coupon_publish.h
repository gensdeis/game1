#pragma once
#include <vector>
#include <string>
#include "mps_item_id.h"

namespace mir3d
{
	class mrpcs_coupon_publish 
	{
	public:
		int32_t seq{};
	public:
		int32_t coupon_type{};
	public:
		int32_t coupon_make_count{};
	public:
		int32_t recevice_start_time{};
	public:
		int32_t recevice_end_time{};
	public:
		int32_t expire_time{};
	public:
		std::string title_text{};
	public:
		std::string contents_text{};
	public:
		std::string memo{};
	public:
		std::vector<mps_item_id> info{};
	public:
		int32_t reg_date{};
	public:
		std::string reg_user{};

	public:
		mrpcs_coupon_publish()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &seq);
			protocol::SerializeType(pBuffer, &coupon_type);
			protocol::SerializeType(pBuffer, &coupon_make_count);
			protocol::SerializeType(pBuffer, &recevice_start_time);
			protocol::SerializeType(pBuffer, &recevice_end_time);
			protocol::SerializeType(pBuffer, &expire_time);
			protocol::SerializeType(pBuffer, &title_text);
			protocol::SerializeType(pBuffer, &contents_text);
			protocol::SerializeType(pBuffer, &memo);
			protocol::SerializeType(pBuffer, &info);
			protocol::SerializeType(pBuffer, &reg_date);
			protocol::SerializeType(pBuffer, &reg_user);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
