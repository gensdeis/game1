#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_indun_monarch_giveup_cs : public BasePacket 	// 요마 던전 전투 포기
	{

	public:
		mp_indun_monarch_giveup_cs() : BasePacket(mpe_cmd::indun_monarch_giveup_cs)
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

	class mp_indun_monarch_giveup_sc : public BasePacket 	// 요마 던전 전투 포기
	{

	public:
		mp_indun_monarch_giveup_sc() : BasePacket(mpe_cmd::indun_monarch_giveup_sc)
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
