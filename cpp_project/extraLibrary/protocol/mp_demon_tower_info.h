#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_demon_tower_info_cs : public BasePacket 
	{

	public:
		mp_demon_tower_info_cs() : BasePacket(mpe_cmd::demon_tower_info_cs)
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

	class mp_demon_tower_info_sc : public BasePacket 
	{
	public:
		uint16_t spawn_index{};	// //위치정보
	public:
		mpe_demon_summon_state state{};	// //
	public:
		int64_t ouid{};	// object uid

	public:
		mp_demon_tower_info_sc() : BasePacket(mpe_cmd::demon_tower_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &spawn_index);
			protocol::SerializeEnum(pBuffer, &state);
			protocol::SerializeType(pBuffer, &ouid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
