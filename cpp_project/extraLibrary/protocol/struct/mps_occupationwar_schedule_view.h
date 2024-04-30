#pragma once
#include <vector>
#include <string>
#include "mps_occupationwar_schedule_info_list.h"

namespace mir3d
{
	class mps_occupationwar_schedule_view 
	{
	public:
		int64_t occupationwar_uid{};
	private:
		bool flag_schedule = false;
		mps_occupationwar_schedule_info_list schedule;
		mps_occupationwar_schedule_info_list* p_schedule = nullptr;
	public:
		bool has_schedule() const
		{
			return flag_schedule;
		}
		mps_occupationwar_schedule_info_list* alloc_schedule()
		{
			flag_schedule = true;
			return &schedule;
		}
		const mps_occupationwar_schedule_info_list* get_schedule() const
		{
			if (true == flag_schedule)
			{
				if (nullptr == p_schedule)
				{
					return &schedule;
				}
				return p_schedule;
			}
			return nullptr;
		}
		void set_schedule(mps_occupationwar_schedule_info_list* in_schedule)
		{
			if (nullptr == p_schedule)
			{
				p_schedule = in_schedule;
				flag_schedule = true;
			}
		}

	public:
		mps_occupationwar_schedule_view()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &occupationwar_uid);
			protocol::SerializeType(pBuffer, &flag_schedule);
			if (true == flag_schedule)
			{
				if (nullptr != p_schedule)
					protocol::SerializeType(pBuffer, p_schedule);
				else
					protocol::SerializeType(pBuffer, &schedule);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
