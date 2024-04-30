#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_user_lock_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		bool locked{};	// true : 잠금 / false : 해제

	public:
		mrpc_gm_user_lock_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_user_lock_cs, tag)
		{
		}
		mrpc_gm_user_lock_cs() : RpcPacket(mpe_rpc_cmd::gm_user_lock_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &locked);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_user_lock_sc : public RpcPacket 
	{

	public:
		mrpc_gm_user_lock_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_user_lock_sc, tag)
		{
		}
		mrpc_gm_user_lock_sc() : RpcPacket(mpe_rpc_cmd::gm_user_lock_sc)
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
