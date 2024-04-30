#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_wanted_murder_target_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		uint8_t wanted_murder_grade{};	// 현상수배단계

	public:
		mrpc_wanted_murder_target_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::wanted_murder_target_cs, tag)
		{
		}
		mrpc_wanted_murder_target_cs() : RpcPacket(mpe_rpc_cmd::wanted_murder_target_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &wanted_murder_grade);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_wanted_murder_target_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		uint8_t wanted_murder_grade{};	// 현상수배단계

	public:
		mrpc_wanted_murder_target_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::wanted_murder_target_sc, tag)
		{
		}
		mrpc_wanted_murder_target_sc() : RpcPacket(mpe_rpc_cmd::wanted_murder_target_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &wanted_murder_grade);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
