#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_redis_rpcinfo.h"

namespace mir3d
{
	class mrpc_update_redis_rpcinfo_cs : public RpcPacket 
	{

	public:
		mrpc_update_redis_rpcinfo_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::update_redis_rpcinfo_cs, tag)
		{
		}
		mrpc_update_redis_rpcinfo_cs() : RpcPacket(mpe_rpc_cmd::update_redis_rpcinfo_cs)
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

	class mrpc_update_redis_rpcinfo_sc : public RpcPacket 
	{
	public:
		std::vector<mrpcs_redis_rpcinfo> list{};

	public:
		mrpc_update_redis_rpcinfo_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::update_redis_rpcinfo_sc, tag)
		{
		}
		mrpc_update_redis_rpcinfo_sc() : RpcPacket(mpe_rpc_cmd::update_redis_rpcinfo_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
