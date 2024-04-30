#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gm_siege_warfare_change_state_cs : public BasePacket 
	{
	public:
		mpe_siege_castle_type siege_castle_type{};
	public:
		mpe_siege_warfare_state siege_warfare_state{};

	public:
		mp_gm_siege_warfare_change_state_cs() : BasePacket(mpe_cmd::gm_siege_warfare_change_state_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &siege_castle_type);
			protocol::SerializeEnum(pBuffer, &siege_warfare_state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_siege_warfare_change_state_sc : public BasePacket 
	{

	public:
		mp_gm_siege_warfare_change_state_sc() : BasePacket(mpe_cmd::gm_siege_warfare_change_state_sc)
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

}
