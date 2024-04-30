#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_street_stall_log 
	{
	public:
		int32_t product_id{};	// // table id
	public:
		std::string customer_nickname{};	// // 구매자
	public:
		std::vector<int32_t> result{};	// // 결과
	public:
		int32_t fees{};

	public:
		mps_street_stall_log()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &product_id);
			protocol::SerializeType(pBuffer, &customer_nickname);
			protocol::SerializeType(pBuffer, &result);
			protocol::SerializeType(pBuffer, &fees);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
