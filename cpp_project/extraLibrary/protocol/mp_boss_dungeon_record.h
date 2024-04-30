#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_boss_dungeon_record.h"

namespace mir3d
{
	class mp_boss_dungeon_record_cs : public BasePacket 	// 보스던전 record 리스트 (패치이후 클리어한 던전만 전달)
	{

	public:
		mp_boss_dungeon_record_cs() : BasePacket(mpe_cmd::boss_dungeon_record_cs)
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

	class mp_boss_dungeon_record_sc : public BasePacket 	// 보스던전 record 리스트 (패치이후 클리어한 던전만 전달)
	{
	public:
		std::vector<mps_boss_dungeon_record> record_list{};	// record 리스트

	public:
		mp_boss_dungeon_record_sc() : BasePacket(mpe_cmd::boss_dungeon_record_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &record_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
