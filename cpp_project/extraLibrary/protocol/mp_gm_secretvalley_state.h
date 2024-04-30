#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gm_secretvalley_state_cs : public BasePacket 	// 비곡점령전시작종료명령어
	{
	public:
		uint8_t state{};	// 0:시작 1:종료

	public:
		mp_gm_secretvalley_state_cs() : BasePacket(mpe_cmd::gm_secretvalley_state_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gm_secretvalley_state_sc : public BasePacket 	// 비곡점령전시작종료명령어
	{

	public:
		mp_gm_secretvalley_state_sc() : BasePacket(mpe_cmd::gm_secretvalley_state_sc)
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
