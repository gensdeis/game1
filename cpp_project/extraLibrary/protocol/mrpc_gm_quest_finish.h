#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_gm_quest_finish_cs : public RpcPacket 
	{
	public:
		int64_t cuid{};
	public:
		int64_t auid{};
	public:
		mrpce_quest_type quest_type{};
	public:
		std::vector<uint16_t> quest_tid{};

	public:
		mrpc_gm_quest_finish_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_quest_finish_cs, tag)
		{
		}
		mrpc_gm_quest_finish_cs() : RpcPacket(mpe_rpc_cmd::gm_quest_finish_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeEnum(pBuffer, &quest_type);
			protocol::SerializeType(pBuffer, &quest_tid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gm_quest_finish_sc : public RpcPacket 
	{

	public:
		mrpc_gm_quest_finish_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gm_quest_finish_sc, tag)
		{
		}
		mrpc_gm_quest_finish_sc() : RpcPacket(mpe_rpc_cmd::gm_quest_finish_sc)
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
