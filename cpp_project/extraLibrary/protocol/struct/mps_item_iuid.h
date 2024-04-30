#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_item_iuid 
	{
	public:
		int64_t iuid{};
	public:
		int32_t count{};

	public:
		mps_item_iuid()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &iuid);
			protocol::SerializeType(pBuffer, &count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
