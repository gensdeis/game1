#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_character_ranking_request_info.h"
#include "struct/mrpcs_ranking_data.h"

namespace mir3d
{
	class mrpc_refresh_character_ranking_info_cs : public RpcPacket 
	{
	public:
		std::vector<mrpcs_character_ranking_request_info> request_info{};

	public:
		mrpc_refresh_character_ranking_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::refresh_character_ranking_info_cs, tag)
		{
		}
		mrpc_refresh_character_ranking_info_cs() : RpcPacket(mpe_rpc_cmd::refresh_character_ranking_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &request_info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_refresh_character_ranking_info_sc : public RpcPacket 
	{
	public:
		std::vector<mrpcs_ranking_data> ranking_data{};

	public:
		mrpc_refresh_character_ranking_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::refresh_character_ranking_info_sc, tag)
		{
		}
		mrpc_refresh_character_ranking_info_sc() : RpcPacket(mpe_rpc_cmd::refresh_character_ranking_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &ranking_data);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
