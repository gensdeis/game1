#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_update_speed_hack_check_cs : public RpcPacket 
	{
	public:
		bool check_state{};
	public:
		int32_t check_count{};

	public:
		mrpc_update_speed_hack_check_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::update_speed_hack_check_cs, tag)
		{
		}
		mrpc_update_speed_hack_check_cs() : RpcPacket(mpe_rpc_cmd::update_speed_hack_check_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &check_state);
			protocol::SerializeType(pBuffer, &check_count);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_update_speed_hack_check_sc : public RpcPacket 
	{

	public:
		mrpc_update_speed_hack_check_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::update_speed_hack_check_sc, tag)
		{
		}
		mrpc_update_speed_hack_check_sc() : RpcPacket(mpe_rpc_cmd::update_speed_hack_check_sc)
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
