﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mp_gate_game_setup_hash_select_cs : public BasePacket 
	{
	public:
		int64_t cuid{};
	public:
		std::string game_setup_hash{};
	public:
		mpe_clinet_platform platform{};
	public:
		std::string game_option_hash{};

	public:
		mp_gate_game_setup_hash_select_cs() : BasePacket(mpe_cmd::gate_game_setup_hash_select_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &game_setup_hash);
			protocol::SerializeEnum(pBuffer, &platform);
			protocol::SerializeType(pBuffer, &game_option_hash);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

	class mp_gate_game_setup_hash_select_sc : public BasePacket 
	{
	public:
		bool game_setup{};
	public:
		bool game_option{};

	public:
		mp_gate_game_setup_hash_select_sc() : BasePacket(mpe_cmd::gate_game_setup_hash_select_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &game_setup);
			protocol::SerializeType(pBuffer, &game_option);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
