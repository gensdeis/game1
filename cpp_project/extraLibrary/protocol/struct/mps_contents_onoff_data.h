#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_contents_onoff_data 
	{
	public:
		int32_t param{};
	public:
		bool active{};

	public:
		mps_contents_onoff_data()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &param);
			protocol::SerializeType(pBuffer, &active);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
