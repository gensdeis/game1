#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_meridians_back 
	{
	public:
		int32_t meridians_id{};	// 경락id
	public:
		int32_t level{};	// 경락타동레벨
	public:
		std::vector<int32_t> list_acupoints{};	// 혈도정보

	public:
		mps_meridians_back()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &meridians_id);
			protocol::SerializeType(pBuffer, &level);
			protocol::SerializeType(pBuffer, &list_acupoints);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
