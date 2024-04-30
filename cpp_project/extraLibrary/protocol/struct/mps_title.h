#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_title 
	{
	public:
		int32_t gid{};
	public:
		int32_t index{};
	public:
		int32_t value{};
	public:
		bool possession{};
	public:
		int64_t end_date{};	// 기간제(0일경우 무제한)

	public:
		mps_title()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &index);
			protocol::SerializeType(pBuffer, &value);
			protocol::SerializeType(pBuffer, &possession);
			protocol::SerializeType(pBuffer, &end_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
