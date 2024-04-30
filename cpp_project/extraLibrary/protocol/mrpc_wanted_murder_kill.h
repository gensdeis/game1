#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_wanted_murder_kill_cs : public RpcPacket 
	{
	public:
		int64_t target_cuid{};
	public:
		int64_t kill_cuid{};

	public:
		mrpc_wanted_murder_kill_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::wanted_murder_kill_cs, tag)
		{
		}
		mrpc_wanted_murder_kill_cs() : RpcPacket(mpe_rpc_cmd::wanted_murder_kill_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &target_cuid);
			protocol::SerializeType(pBuffer, &kill_cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_wanted_murder_kill_sc : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		std::string target_nick_name{};
	public:
		bool result{};

	public:
		mrpc_wanted_murder_kill_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::wanted_murder_kill_sc, tag)
		{
		}
		mrpc_wanted_murder_kill_sc() : RpcPacket(mpe_rpc_cmd::wanted_murder_kill_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &target_nick_name);
			protocol::SerializeType(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
