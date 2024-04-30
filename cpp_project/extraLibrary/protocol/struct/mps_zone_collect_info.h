#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_zone_collect_info 
	{
	public:
		bool enable{};	// 채광오브젝트enable유무
	public:
		int32_t count{};	// 채광수량
	public:
		int64_t owner_uid{};	// 소유자 정보

	public:
		mps_zone_collect_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &enable);
			protocol::SerializeType(pBuffer, &count);
			protocol::SerializeType(pBuffer, &owner_uid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
