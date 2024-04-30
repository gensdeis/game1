#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_street_stall_get_use_count_cs : public BasePacket 	// // 개인노점 제작 가능 횟수 정보 요청
	{
	public:
		int64_t suid{};

	public:
		mp_street_stall_get_use_count_cs() : BasePacket(mpe_cmd::street_stall_get_use_count_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &suid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_street_stall_get_use_count_sc : public BasePacket 	// // 개인노점 제작 가능 횟수 정보 요청
	{
	public:
		int32_t use_count{};	// // 제작 가능 횟수

	public:
		mp_street_stall_get_use_count_sc() : BasePacket(mpe_cmd::street_stall_get_use_count_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &use_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
