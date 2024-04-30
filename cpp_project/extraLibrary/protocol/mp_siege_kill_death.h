#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_siege_kill_death_cs : public BasePacket 
	{

	public:
		mp_siege_kill_death_cs() : BasePacket(mpe_cmd::siege_kill_death_cs)
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

	class mp_siege_kill_death_sc : public BasePacket 
	{
	public:
		uint16_t kill{};
	public:
		uint16_t death{};

	public:
		mp_siege_kill_death_sc() : BasePacket(mpe_cmd::siege_kill_death_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &kill);
			protocol::SerializeType(pBuffer, &death);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
