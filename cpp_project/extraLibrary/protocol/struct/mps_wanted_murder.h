#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_wanted_murder 
	{
	public:
		int64_t record_id{};
	public:
		int64_t target_cuid{};

	public:
		mps_wanted_murder()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &record_id);
			protocol::SerializeType(pBuffer, &target_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
