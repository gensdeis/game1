#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_ranking_data_update_cs : public RpcPacket 
	{
	public:
		mpe_ranking_type rank_type{};

	public:
		mrpc_ranking_data_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::ranking_data_update_cs, tag)
		{
		}
		mrpc_ranking_data_update_cs() : RpcPacket(mpe_rpc_cmd::ranking_data_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &rank_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_ranking_data_update_sc : public RpcPacket 
	{
	public:
		mpe_error result{};

	public:
		mrpc_ranking_data_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::ranking_data_update_sc, tag)
		{
		}
		mrpc_ranking_data_update_sc() : RpcPacket(mpe_rpc_cmd::ranking_data_update_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &result);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
