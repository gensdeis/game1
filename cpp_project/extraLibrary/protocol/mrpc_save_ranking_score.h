#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_save_ranking_score_cs : public RpcPacket 
	{
	public:
		int64_t uid{};
	public:
		int32_t gid{};
	public:
		mpe_ranking_type rank_type{};
	public:
		mrpce_ranking_update_type update_type{};
	public:
		int64_t score{};
	public:
		int64_t update_timestamp{};

	public:
		mrpc_save_ranking_score_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::save_ranking_score_cs, tag)
		{
		}
		mrpc_save_ranking_score_cs() : RpcPacket(mpe_rpc_cmd::save_ranking_score_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &gid);
			protocol::SerializeEnum(pBuffer, &rank_type);
			protocol::SerializeEnum(pBuffer, &update_type);
			protocol::SerializeType(pBuffer, &score);
			protocol::SerializeType(pBuffer, &update_timestamp);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_save_ranking_score_sc : public RpcPacket 
	{

	public:
		mrpc_save_ranking_score_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::save_ranking_score_sc, tag)
		{
		}
		mrpc_save_ranking_score_sc() : RpcPacket(mpe_rpc_cmd::save_ranking_score_sc)
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
