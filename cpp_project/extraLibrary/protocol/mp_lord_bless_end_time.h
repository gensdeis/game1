#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_lord_bless_end_time_cs : public BasePacket 
	{

	public:
		mp_lord_bless_end_time_cs() : BasePacket(mpe_cmd::lord_bless_end_time_cs)
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

	class mp_lord_bless_end_time_sc : public BasePacket 
	{
	public:
		int32_t last_end_time{};	// 마지막종료시간

	public:
		mp_lord_bless_end_time_sc() : BasePacket(mpe_cmd::lord_bless_end_time_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &last_end_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
