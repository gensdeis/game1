#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_occupationwar_tender_total_info_cs : public RpcPacket 
	{

	public:
		mrpc_occupationwar_tender_total_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::occupationwar_tender_total_info_cs, tag)
		{
		}
		mrpc_occupationwar_tender_total_info_cs() : RpcPacket(mpe_rpc_cmd::occupationwar_tender_total_info_cs)
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

	class mrpc_occupationwar_tender_total_info_sc : public RpcPacket 
	{
	public:
		int32_t gid{};
	public:
		int64_t totoal_server{};

	public:
		mrpc_occupationwar_tender_total_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::occupationwar_tender_total_info_sc, tag)
		{
		}
		mrpc_occupationwar_tender_total_info_sc() : RpcPacket(mpe_rpc_cmd::occupationwar_tender_total_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeType(pBuffer, &totoal_server);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
