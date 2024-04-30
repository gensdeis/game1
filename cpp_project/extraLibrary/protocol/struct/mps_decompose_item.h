#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_decompose_item 
	{
	public:
		int64_t iuid{};
	public:
		int32_t count{};
	public:
		bool check_use{};	// 개별 분해제 사용여부

	public:
		mps_decompose_item()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &check_use);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
