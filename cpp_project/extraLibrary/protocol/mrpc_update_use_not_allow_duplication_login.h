#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_update_use_not_allow_duplication_login_cs : public RpcPacket 
	{
	public:
		bool check_state{};

	public:
		mrpc_update_use_not_allow_duplication_login_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::update_use_not_allow_duplication_login_cs, tag)
		{
		}
		mrpc_update_use_not_allow_duplication_login_cs() : RpcPacket(mpe_rpc_cmd::update_use_not_allow_duplication_login_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &check_state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_update_use_not_allow_duplication_login_sc : public RpcPacket 
	{
	public:
		bool check_state{};

	public:
		mrpc_update_use_not_allow_duplication_login_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::update_use_not_allow_duplication_login_sc, tag)
		{
		}
		mrpc_update_use_not_allow_duplication_login_sc() : RpcPacket(mpe_rpc_cmd::update_use_not_allow_duplication_login_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &check_state);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
