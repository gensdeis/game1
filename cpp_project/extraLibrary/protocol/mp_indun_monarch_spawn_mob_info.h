#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_monarch_info.h"

namespace mir3d
{
	class mp_indun_monarch_spawn_mob_info_cs : public BasePacket 
	{

	public:
		mp_indun_monarch_spawn_mob_info_cs() : BasePacket(mpe_cmd::indun_monarch_spawn_mob_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_indun_monarch_spawn_mob_info_sc : public BasePacket 
	{
	public:
		std::vector<mps_monarch_info> list_monarch_info{};	// item_id별 소환사냥 진행정보

	public:
		mp_indun_monarch_spawn_mob_info_sc() : BasePacket(mpe_cmd::indun_monarch_spawn_mob_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_monarch_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
