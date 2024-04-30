#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_quest_giveup_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};
	public:
		std::vector<uint16_t> id_list{};

	public:
		mrpc_quest_giveup_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::quest_giveup_cs, tag)
		{
		}
		mrpc_quest_giveup_cs() : RpcPacket(mpe_rpc_cmd::quest_giveup_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeType(pBuffer, &id_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_quest_giveup_sc : public RpcPacket 
	{
	public:
		int64_t key{};

	public:
		mrpc_quest_giveup_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::quest_giveup_sc, tag)
		{
		}
		mrpc_quest_giveup_sc() : RpcPacket(mpe_rpc_cmd::quest_giveup_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
