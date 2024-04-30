#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_game_option.h"

namespace mir3d
{
	class mrpc_gate_game_option_select_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		mpe_clinet_platform platform{};

	public:
		mrpc_gate_game_option_select_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_game_option_select_cs, tag)
		{
		}
		mrpc_gate_game_option_select_cs() : RpcPacket(mpe_rpc_cmd::gate_game_option_select_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &platform);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_game_option_select_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	private:
		bool flag_game_setup = false;
		mps_game_option game_setup;
		mps_game_option* p_game_setup = nullptr;
	public:
		bool has_game_setup() const
		{
			return flag_game_setup;
		}
		mps_game_option* alloc_game_setup()
		{
			flag_game_setup = true;
			return &game_setup;
		}
		const mps_game_option* get_game_setup() const
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
		void set_game_setup(mps_game_option* in_game_setup)
		{
			if (nullptr == p_game_setup)
			{
				p_game_setup = in_game_setup;
				flag_game_setup = true;
			}
		}

	public:
		mrpc_gate_game_option_select_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_game_option_select_sc, tag)
		{
		}
		mrpc_gate_game_option_select_sc() : RpcPacket(mpe_rpc_cmd::gate_game_option_select_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
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
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
