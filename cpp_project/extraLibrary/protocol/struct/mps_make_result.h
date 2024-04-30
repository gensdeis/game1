#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_make_result 
	{
	public:
		mpe_make_result result{};	// "//대성공,성공,실패"
	public:
		int32_t count{};	// //결과에따른수량

	public:
		mps_make_result()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &result);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
