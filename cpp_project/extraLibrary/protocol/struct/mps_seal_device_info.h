#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_seal_device_info 
	{
	public:
		mpe_seal_device_state state{};	// 상태
	public:
		int32_t wait_time{};	// 활성화대기시간

	public:
		mps_seal_device_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &wait_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
