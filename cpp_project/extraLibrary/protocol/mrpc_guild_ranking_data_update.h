#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_guild_ranking_info.h"

namespace mir3d
{
	class mrpc_guild_ranking_data_update_cs : public RpcPacket 
	{
	public:
		std::vector<mrpcs_guild_ranking_info> ranking_list{};

	public:
		mrpc_guild_ranking_data_update_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_ranking_data_update_cs, tag)
		{
		}
		mrpc_guild_ranking_data_update_cs() : RpcPacket(mpe_rpc_cmd::guild_ranking_data_update_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ranking_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_guild_ranking_data_update_sc : public RpcPacket 
	{

	public:
		mrpc_guild_ranking_data_update_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::guild_ranking_data_update_sc, tag)
		{
		}
		mrpc_guild_ranking_data_update_sc() : RpcPacket(mpe_rpc_cmd::guild_ranking_data_update_sc)
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
