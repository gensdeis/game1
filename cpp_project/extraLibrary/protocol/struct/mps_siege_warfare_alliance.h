#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_siege_warfare_alliance 	// 연합상태
	{
	public:
		int64_t guid{};
	public:
		bool accept{};	// 승인여부

	public:
		mps_siege_warfare_alliance()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &guid);
			protocol::SerializeType(pBuffer, &accept);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
