#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_darksteel_box_keep 
	{
	public:
		int64_t i{};
	public:
		int32_t d{};
	public:
		int32_t u{};
	public:
		int32_t w{};
	public:
		int64_t t{};

	public:
		mps_darksteel_box_keep()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &i);
			protocol::SerializeType(pBuffer, &d);
			protocol::SerializeType(pBuffer, &u);
			protocol::SerializeType(pBuffer, &w);
			protocol::SerializeType(pBuffer, &t);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
