#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_restore_noti 	// 신룡의축복 noti
	{
	public:
		mpe_restore_event_type type{};	// 타입
	public:
		bool exists{};	// 합성가능여부

	public:
		mps_restore_noti()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &exists);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
