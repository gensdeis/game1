#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_siege_warfare_time_info 	// 공성전 날짜
	{
	public:
		mpe_siege_castle_type castle_type{};
	public:
		int64_t siege_time{};

	public:
		mps_siege_warfare_time_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &castle_type);
			protocol::SerializeType(pBuffer, &siege_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
