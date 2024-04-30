#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_wanted_murder_number_of_uses_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int32_t wanted_murder_reg_count{};
	public:
		int32_t wanted_murder_accept_count{};
	public:
		int64_t wanted_murder_reset_time{};

	public:
		mrpc_wanted_murder_number_of_uses_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::wanted_murder_number_of_uses_cs, tag)
		{
		}
		mrpc_wanted_murder_number_of_uses_cs() : RpcPacket(mpe_rpc_cmd::wanted_murder_number_of_uses_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &wanted_murder_reg_count);
			protocol::SerializeType(pBuffer, &wanted_murder_accept_count);
			protocol::SerializeType(pBuffer, &wanted_murder_reset_time);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_wanted_murder_number_of_uses_sc : public RpcPacket 
	{

	public:
		mrpc_wanted_murder_number_of_uses_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::wanted_murder_number_of_uses_sc, tag)
		{
		}
		mrpc_wanted_murder_number_of_uses_sc() : RpcPacket(mpe_rpc_cmd::wanted_murder_number_of_uses_sc)
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
