﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_character_simple_info.h"

namespace mir3d
{
	class mp_gate_friend_requested_list_cs : public BasePacket 
	{
	public:
		int64_t cuid{};

	public:
		mp_gate_friend_requested_list_cs() : BasePacket(mpe_cmd::gate_friend_requested_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_friend_requested_list_sc : public BasePacket 
	{
	public:
		std::vector<mps_character_simple_info> requested_list{};
	public:
		int32_t friend_count{};

	public:
		mp_gate_friend_requested_list_sc() : BasePacket(mpe_cmd::gate_friend_requested_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &requested_list);
			protocol::SerializeType(pBuffer, &friend_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}