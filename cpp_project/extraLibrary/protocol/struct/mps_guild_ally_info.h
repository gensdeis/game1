#pragma once
#include <vector>
#include <string>
#include "mps_other_guild_info.h"

namespace mir3d
{
	class mps_guild_ally_info 
	{
	private:
		bool flag_ally_info = false;
		mps_other_guild_info ally_info;	// "동맹길드정보. 동맹여부 1 일떄만 유효."
		mps_other_guild_info* p_ally_info = nullptr;
	public:
		bool has_ally_info() const
		{
			return flag_ally_info;
		}
		mps_other_guild_info* alloc_ally_info()
		{
			flag_ally_info = true;
			return &ally_info;
		}
		const mps_other_guild_info* get_ally_info() const
		{
			if (true == flag_ally_info)
			{
				if (nullptr == p_ally_info)
				{
					return &ally_info;
				}
				return p_ally_info;
			}
			return nullptr;
		}
		void set_ally_info(mps_other_guild_info* in_ally_info)
		{
			if (nullptr == p_ally_info)
			{
				p_ally_info = in_ally_info;
				flag_ally_info = true;
			}
		}
	public:
		int64_t ally_guid{};	// "동맹길드uid"
	public:
		int64_t ally_time{};	// "동맹맺은시간"
	public:
		int64_t cancel_time{};	// "동맹해제시간"
	public:
		uint8_t is_ally{};	// "동맹여부 0:해제, 1:맺음"
	public:
		uint8_t slot{};	// "동맹슬롯 1~3"

	public:
		mps_guild_ally_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &flag_ally_info);
			if (true == flag_ally_info)
			{
				if (nullptr != p_ally_info)
					protocol::SerializeType(pBuffer, p_ally_info);
				else
					protocol::SerializeType(pBuffer, &ally_info);
			}
			protocol::SerializeType(pBuffer, &ally_guid);
			protocol::SerializeType(pBuffer, &ally_time);
			protocol::SerializeType(pBuffer, &cancel_time);
			protocol::SerializeType(pBuffer, &is_ally);
			protocol::SerializeType(pBuffer, &slot);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
