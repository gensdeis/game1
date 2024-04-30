#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_zone_boss_dead_cs : public BasePacket 
	{

	public:
		mp_zone_boss_dead_cs() : BasePacket(mpe_cmd::zone_boss_dead_cs)
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

	class mp_zone_boss_dead_sc : public BasePacket 
	{
	public:
		int32_t tid{};	// 몬스터 tid
	public:
		std::string nickname{};	// 막타를 친 플래이어 

	public:
		mp_zone_boss_dead_sc() : BasePacket(mpe_cmd::zone_boss_dead_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &tid);
			protocol::SerializeType(pBuffer, &nickname);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
