#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_wanted_murder_target_cs : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		uint8_t wanted_murder_grade{};	// 현상수배단계

	public:
		mp_wanted_murder_target_cs() : BasePacket(mpe_cmd::wanted_murder_target_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &wanted_murder_grade);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_wanted_murder_target_sc : public BasePacket 
	{
	public:
		uint8_t wanted_murder_grade{};	// 현상수배단계

	public:
		mp_wanted_murder_target_sc() : BasePacket(mpe_cmd::wanted_murder_target_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &wanted_murder_grade);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
