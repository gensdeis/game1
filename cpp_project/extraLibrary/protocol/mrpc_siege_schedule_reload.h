#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_siege_schedule_reload_cs : public RpcPacket 
	{

	public:
		mrpc_siege_schedule_reload_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_schedule_reload_cs, tag)
		{
		}
		mrpc_siege_schedule_reload_cs() : RpcPacket(mpe_rpc_cmd::siege_schedule_reload_cs)
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

	class mrpc_siege_schedule_reload_sc : public RpcPacket 
	{

	public:
		mrpc_siege_schedule_reload_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_schedule_reload_sc, tag)
		{
		}
		mrpc_siege_schedule_reload_sc() : RpcPacket(mpe_rpc_cmd::siege_schedule_reload_sc)
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
