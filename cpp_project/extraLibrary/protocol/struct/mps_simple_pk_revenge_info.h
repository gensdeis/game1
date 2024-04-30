#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_simple_pk_revenge_info 
	{
	public:
		int64_t record_id{};
	public:
		int64_t cuid{};

	public:
		mps_simple_pk_revenge_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &record_id);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
