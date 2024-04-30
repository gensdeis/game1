#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_ranking_data.h"

namespace mir3d
{
	class mrpc_reinitialize_ranking_info_cs : public RpcPacket 
	{
	public:
		mpe_ranking_type ranking_type{};

	public:
		mrpc_reinitialize_ranking_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::reinitialize_ranking_info_cs, tag)
		{
		}
		mrpc_reinitialize_ranking_info_cs() : RpcPacket(mpe_rpc_cmd::reinitialize_ranking_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &ranking_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_reinitialize_ranking_info_sc : public RpcPacket 
	{
	public:
		std::vector<mrpcs_ranking_data> ranking_data{};
	public:
		mpe_ranking_type ranking_type{};

	public:
		mrpc_reinitialize_ranking_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::reinitialize_ranking_info_sc, tag)
		{
		}
		mrpc_reinitialize_ranking_info_sc() : RpcPacket(mpe_rpc_cmd::reinitialize_ranking_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ranking_data);
			protocol::SerializeEnum(pBuffer, &ranking_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
