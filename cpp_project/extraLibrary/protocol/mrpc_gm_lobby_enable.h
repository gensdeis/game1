#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_lobby_enable_cs : public RpcPacket 
	{
	public:
		bool state{};

	public:
		mrpc_gm_lobby_enable_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_lobby_enable_cs, tag)
		{
		}
		mrpc_gm_lobby_enable_cs() : RpcPacket(mpe_rpc_cmd::gm_lobby_enable_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_lobby_enable_sc : public RpcPacket 
	{

	public:
		mrpc_gm_lobby_enable_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_lobby_enable_sc, tag)
		{
		}
		mrpc_gm_lobby_enable_sc() : RpcPacket(mpe_rpc_cmd::gm_lobby_enable_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
