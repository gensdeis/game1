#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_achieve_rate_info 
	{
	public:
		int32_t collection_id{};
	public:
		std::vector<int32_t> type_rate{};
	public:
		int32_t total_rate{};
	public:
		int32_t value{};	// 보상받은 목록(비트)

	public:
		mps_achieve_rate_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &collection_id);
			protocol::SerializeType(pBuffer, &type_rate);
			protocol::SerializeType(pBuffer, &total_rate);
			protocol::SerializeType(pBuffer, &value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
