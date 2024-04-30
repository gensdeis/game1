#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mrpcs_occupationwar_schedule_noti 
	{
	public:
		mrpce_occupationwar_war_schedule_noti_type noti{};
	public:
		bool state{};

	public:
		mrpcs_occupationwar_schedule_noti()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &noti);
			protocol::SerializeType(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
