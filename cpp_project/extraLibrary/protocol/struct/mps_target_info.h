#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_target_info 
	{
	public:
		int64_t uuid{};	// //타겟 uid
	public:
		int32_t type{};	// //타겟 object type
	public:
		int32_t tile_index{};	// //타겟 cell index

	public:
		mps_target_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &uuid);
			protocol::SerializeType(pBuffer, &type);
			protocol::SerializeType(pBuffer, &tile_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
