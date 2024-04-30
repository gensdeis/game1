#pragma once
#include <vector>
#include <string>
#include "mps_secretvalley_owner_info.h"
#include "mrpcs_occupationwar_war_map_info.h"
#include "mrpcs_occupationwar_owner_disqualify.h"

namespace mir3d
{
	class mrpcs_occupationwar_game_info 
	{
	public:
		mpe_secretvalley_state state{};
	public:
		int32_t zone_id{};
	public:
		int64_t channel_uid{};
	public:
		int32_t start_time{};
	public:
		int32_t end_time{};
	private:
		bool flag_owner_info = false;
		mps_secretvalley_owner_info owner_info;
		mps_secretvalley_owner_info* p_owner_info = nullptr;
	public:
		bool has_owner_info() const
		{
			return flag_owner_info;
		}
		mps_secretvalley_owner_info* alloc_owner_info()
		{
			flag_owner_info = true;
			return &owner_info;
		}
		const mps_secretvalley_owner_info* get_owner_info() const
		{
			if (true == flag_owner_info)
			{
				if (nullptr == p_owner_info)
				{
					return &owner_info;
				}
				return p_owner_info;
			}
			return nullptr;
		}
		void set_owner_info(mps_secretvalley_owner_info* in_owner_info)
		{
			if (nullptr == p_owner_info)
			{
				p_owner_info = in_owner_info;
				flag_owner_info = true;
			}
		}
	public:
		bool decide{};
	public:
		std::vector<mrpcs_occupationwar_war_map_info> list_guild{};
	public:
		std::vector<mrpcs_occupationwar_owner_disqualify> list_disqualify{};

	public:
		mrpcs_occupationwar_game_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &zone_id);
			protocol::SerializeType(pBuffer, &channel_uid);
			protocol::SerializeType(pBuffer, &start_time);
			protocol::SerializeType(pBuffer, &end_time);
			protocol::SerializeType(pBuffer, &flag_owner_info);
			if (true == flag_owner_info)
			{
				if (nullptr != p_owner_info)
					protocol::SerializeType(pBuffer, p_owner_info);
				else
					protocol::SerializeType(pBuffer, &owner_info);
			}
			protocol::SerializeType(pBuffer, &decide);
			protocol::SerializeType(pBuffer, &list_guild);
			protocol::SerializeType(pBuffer, &list_disqualify);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
