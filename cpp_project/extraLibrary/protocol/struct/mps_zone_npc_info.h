#pragma once
#include <vector>
#include <string>

namespace mir3d
{
	class mps_zone_npc_info 
	{
	public:
		int32_t hp{};
	public:
		int32_t mhp{};
	public:
		int32_t mp{};
	public:
		int32_t mmp{};
	public:
		int32_t object_id{};

	public:
		mps_zone_npc_info()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &hp);
			protocol::SerializeType(pBuffer, &mhp);
			protocol::SerializeType(pBuffer, &mp);
			protocol::SerializeType(pBuffer, &mmp);
			protocol::SerializeType(pBuffer, &object_id);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
