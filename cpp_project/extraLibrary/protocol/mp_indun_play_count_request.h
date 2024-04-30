#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_indun_play_count_request.h"

namespace mir3d
{
	class mp_indun_play_count_request_cs : public BasePacket 
	{

	public:
		mp_indun_play_count_request_cs() : BasePacket(mpe_cmd::indun_play_count_request_cs)
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

	class mp_indun_play_count_request_sc : public BasePacket 
	{
	public:
		std::vector<mps_indun_play_count_request> list_indun_play_count{};

	public:
		mp_indun_play_count_request_sc() : BasePacket(mpe_cmd::indun_play_count_request_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list_indun_play_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
