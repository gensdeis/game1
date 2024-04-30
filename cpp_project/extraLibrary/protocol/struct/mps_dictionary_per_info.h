#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_dictionary_per_info 
	{
	public:
		int32_t category_id{};
	public:
		int32_t value{};	// 카테고리별 %

	public:
		mps_dictionary_per_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &category_id);
			protocol::SerializeType(pBuffer, &value);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
