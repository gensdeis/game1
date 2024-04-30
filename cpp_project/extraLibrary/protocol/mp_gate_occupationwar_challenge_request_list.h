#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_occupationwar_challenge_guild_info.h"

namespace mir3d
{
	class mp_gate_occupationwar_challenge_request_list_cs : public BasePacket 	// 비곡점령전 신청 내역 조회
	{

	public:
		mp_gate_occupationwar_challenge_request_list_cs() : BasePacket(mpe_cmd::gate_occupationwar_challenge_request_list_cs)
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

	class mp_gate_occupationwar_challenge_request_list_sc : public BasePacket 	// 비곡점령전 신청 내역 조회
	{
	public:
		std::vector<mps_occupationwar_challenge_guild_info> list{};

	public:
		mp_gate_occupationwar_challenge_request_list_sc() : BasePacket(mpe_cmd::gate_occupationwar_challenge_request_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
