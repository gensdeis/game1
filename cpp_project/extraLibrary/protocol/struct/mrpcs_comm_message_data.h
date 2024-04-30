#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_comm_message_data 
	{
	public:
		int32_t use_count{};
	public:
		int64_t reset_time{};
	public:
		int64_t cool_time{};
	public:
		int64_t life_time{};
	public:
		mpe_event_ingame event_type{};
	public:
		bool event_active{};

	public:
		mrpcs_comm_message_data()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &use_count);
			protocol::SerializeType(pBuffer, &reset_time);
			protocol::SerializeType(pBuffer, &cool_time);
			protocol::SerializeType(pBuffer, &life_time);
			protocol::SerializeEnum(pBuffer, &event_type);
			protocol::SerializeType(pBuffer, &event_active);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
