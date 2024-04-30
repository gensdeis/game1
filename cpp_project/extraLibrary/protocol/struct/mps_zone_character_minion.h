#pragma once
#include <vector>
#include <string>
#include "mps_buff.h"

namespace mir3d
{
	class mps_zone_character_minion 
	{
	public:
		int64_t owner_uid{};	// owneruid
	public:
		int32_t hp{};	// HP
	public:
		int32_t mhp{};	// maxHP
	public:
		int64_t owner_guid{};	// 소유자 소속 문파 guid
	public:
		std::vector<mps_buff> buff_list{};
	public:
		bool respawn{};	// respawn = true / 소환(appread)

	public:
		mps_zone_character_minion()
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			protocol::SerializeType(pBuffer, &owner_uid);
			protocol::SerializeType(pBuffer, &hp);
			protocol::SerializeType(pBuffer, &mhp);
			protocol::SerializeType(pBuffer, &owner_guid);
			protocol::SerializeType(pBuffer, &buff_list);
			protocol::SerializeType(pBuffer, &respawn);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
		}
	};
}
