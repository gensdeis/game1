#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_occupationwar_challenge_request_cs : public BasePacket 	// 비곡점령전 신청
	{
	public:
		mpe_occupationwar_map_type map_type{};	// 비곡종류
	public:
		uint8_t challenge{};	// 0 : 신청, 1 : 취소

	public:
		mp_occupationwar_challenge_request_cs() : BasePacket(mpe_cmd::occupationwar_challenge_request_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &map_type);
			protocol::SerializeType(pBuffer, &challenge);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_occupationwar_challenge_request_sc : public BasePacket 	// 비곡점령전 신청
	{
	public:
		mpe_error error_code{};
	public:
		mpe_occupationwar_map_type map_type{};	// 비곡종류

	public:
		mp_occupationwar_challenge_request_sc() : BasePacket(mpe_cmd::occupationwar_challenge_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &error_code);
			protocol::SerializeEnum(pBuffer, &map_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
