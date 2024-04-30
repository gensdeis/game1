#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_gate_character_reconnect_info.h"

namespace mir3d
{
	class mrpc_gate_lobby_character_socket_reconnect_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};

	public:
		mrpc_gate_lobby_character_socket_reconnect_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_lobby_character_socket_reconnect_cs, tag)
		{
		}
		mrpc_gate_lobby_character_socket_reconnect_cs() : RpcPacket(mpe_rpc_cmd::gate_lobby_character_socket_reconnect_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_lobby_character_socket_reconnect_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	private:
		bool flag_info = false;
		mrpcs_gate_character_reconnect_info info;
		mrpcs_gate_character_reconnect_info* p_info = nullptr;
	public:
		bool has_info() const
		{
			return flag_info;
		}
		mrpcs_gate_character_reconnect_info* alloc_info()
		{
			flag_info = true;
			return &info;
		}
		const mrpcs_gate_character_reconnect_info* get_info() const
		{
			if (true == flag_info)
			{
				if (nullptr == p_info)
				{
					return &info;
				}
				return p_info;
			}
			return nullptr;
		}
		void set_info(mrpcs_gate_character_reconnect_info* in_info)
		{
			if (nullptr == p_info)
			{
				p_info = in_info;
				flag_info = true;
			}
		}

	public:
		mrpc_gate_lobby_character_socket_reconnect_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_lobby_character_socket_reconnect_sc, tag)
		{
		}
		mrpc_gate_lobby_character_socket_reconnect_sc() : RpcPacket(mpe_rpc_cmd::gate_lobby_character_socket_reconnect_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &flag_info);
			if (true == flag_info)
			{
				if (nullptr != p_info)
					protocol::SerializeType(pBuffer, p_info);
				else
					protocol::SerializeType(pBuffer, &info);
			}
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
