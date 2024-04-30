#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_seasonpass_challenge.h"

namespace mir3d
{
	class mp_seasonpass_challenge_update_cs : public BasePacket 
	{

	public:
		mp_seasonpass_challenge_update_cs() : BasePacket(mpe_cmd::seasonpass_challenge_update_cs)
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

	class mp_seasonpass_challenge_update_sc : public BasePacket 
	{
	public:
		std::vector<mps_seasonpass_challenge> list_challenge{};

	public:
		mp_seasonpass_challenge_update_sc() : BasePacket(mpe_cmd::seasonpass_challenge_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_challenge);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
