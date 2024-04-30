﻿#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_game_setup.h"

namespace mir3d
{
	class mp_gate_game_setup_select_cs : public BasePacket 
	{
	public:
		int64_t cuid{};

	public:
		mp_gate_game_setup_select_cs() : BasePacket(mpe_cmd::gate_game_setup_select_cs)
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

	class mp_gate_game_setup_select_sc : public BasePacket 
	{
	private:
		bool flag_game_setup = false;
		mps_game_setup game_setup;
		mps_game_setup* p_game_setup = nullptr;
	public:
		bool has_game_setup() const
		{
			return flag_game_setup;
		}
		mps_game_setup* alloc_game_setup()
		{
			flag_game_setup = true;
			return &game_setup;
		}
		const mps_game_setup* get_game_setup() const
		{
			if (true == flag_game_setup)
			{
				if (nullptr == p_game_setup)
				{
					return &game_setup;
				}
				return p_game_setup;
			}
			return nullptr;
		}
		void set_game_setup(mps_game_setup* in_game_setup)
		{
			if (nullptr == p_game_setup)
			{
				p_game_setup = in_game_setup;
				flag_game_setup = true;
			}
		}

	public:
		mp_gate_game_setup_select_sc() : BasePacket(mpe_cmd::gate_game_setup_select_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			BasePacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &flag_game_setup);
			if (true == flag_game_setup)
			{
				if (nullptr != p_game_setup)
					protocol::SerializeType(pBuffer, p_game_setup);
				else
					protocol::SerializeType(pBuffer, &game_setup);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			BasePacket::SerializeEnd(pBuffer, length);
		}
	};

}
