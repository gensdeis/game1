﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_illusion_dungeon_time_out_cs : public BasePacket 
	{

	public:
		mp_illusion_dungeon_time_out_cs() : BasePacket(mpe_cmd::illusion_dungeon_time_out_cs)
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

	class mp_illusion_dungeon_time_out_sc : public BasePacket 
	{

	public:
		mp_illusion_dungeon_time_out_sc() : BasePacket(mpe_cmd::illusion_dungeon_time_out_sc)
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