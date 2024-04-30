#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_channel_status_info 
	{
	public:
		int32_t map_id{};
	public:
		uint16_t channel_id{};
	public:
		mpe_state state{};

	public:
		mps_channel_status_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &map_id);
			protocol::SerializeType(pBuffer, &channel_id);
			protocol::SerializeEnum(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
