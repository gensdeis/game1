#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_make_item 
	{
	public:
		int32_t tid{};
	public:
		int32_t make_count{};
	public:
		int32_t reset_date{};

	public:
		mps_make_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &make_count);
			protocol::SerializeType(pBuffer, &reset_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
