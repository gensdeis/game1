#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_occupationwar_challenge_request_info_cs : public BasePacket 	// 비곡점령전 신청 정보
	{

	public:
		mp_occupationwar_challenge_request_info_cs() : BasePacket(mpe_cmd::occupationwar_challenge_request_info_cs)
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

	class mp_occupationwar_challenge_request_info_sc : public BasePacket 	// 비곡점령전 신청 정보
	{
	public:
		bool request_availability{};	// 청가능여부 (서버), true 면 신청가능한 서버
	public:
		mpe_occupationwar_map_type map_type{};	// 비곡종류 - none 이면 안한거
	public:
		int32_t request_start{};	// 참가신청 시작 시간
	public:
		int32_t request_end{};	// 참가신청 마감 시간

	public:
		mp_occupationwar_challenge_request_info_sc() : BasePacket(mpe_cmd::occupationwar_challenge_request_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &request_availability);
			protocol::SerializeEnum(pBuffer, &map_type);
			protocol::SerializeType(pBuffer, &request_start);
			protocol::SerializeType(pBuffer, &request_end);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
