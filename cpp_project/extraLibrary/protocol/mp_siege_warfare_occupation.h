#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_siege_warfare_occupation_cs : public BasePacket 
	{

	public:
		mp_siege_warfare_occupation_cs() : BasePacket(mpe_cmd::siege_warfare_occupation_cs)
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

	class mp_siege_warfare_occupation_sc : public BasePacket 
	{
	public:
		bool is_occupation{};	// 공성 점령 시작/취소 여부 (true : 시작/false : 취소)

	public:
		mp_siege_warfare_occupation_sc() : BasePacket(mpe_cmd::siege_warfare_occupation_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &is_occupation);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
