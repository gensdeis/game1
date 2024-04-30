#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_update_max_hp_mp_cs : public BasePacket 
	{

	public:
		mp_update_max_hp_mp_cs() : BasePacket(mpe_cmd::update_max_hp_mp_cs)
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

	class mp_update_max_hp_mp_sc : public BasePacket 
	{
	public:
		int32_t max_hp{};
	public:
		int32_t max_mp{};

	public:
		mp_update_max_hp_mp_sc() : BasePacket(mpe_cmd::update_max_hp_mp_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &max_hp);
			protocol::SerializeType(pBuffer, &max_mp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
