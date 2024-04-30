#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_community_object_run_time_update_cs : public RpcPacket 
	{
	public:
		int64_t ouid{};	// // com object uid

	public:
		mrpc_community_object_run_time_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_object_run_time_update_cs, tag)
		{
		}
		mrpc_community_object_run_time_update_cs() : RpcPacket(mpe_rpc_cmd::community_object_run_time_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ouid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_community_object_run_time_update_sc : public RpcPacket 
	{

	public:
		mrpc_community_object_run_time_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::community_object_run_time_update_sc, tag)
		{
		}
		mrpc_community_object_run_time_update_sc() : RpcPacket(mpe_rpc_cmd::community_object_run_time_update_sc)
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
