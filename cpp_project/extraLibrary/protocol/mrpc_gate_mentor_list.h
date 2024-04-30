#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_mentor.h"
#include "struct/mps_mentor.h"

namespace mir3d
{
	class mrpc_gate_mentor_list_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t auid{};
	public:
		int64_t cuid{};
	public:
		mpe_mentor_type mentor_type{};

	public:
		mrpc_gate_mentor_list_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_mentor_list_cs, tag)
		{
		}
		mrpc_gate_mentor_list_cs() : RpcPacket(mpe_rpc_cmd::gate_mentor_list_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &auid);
			protocol::SerializeType(pBuffer, &cuid);
			protocol::SerializeEnum(pBuffer, &mentor_type);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_gate_mentor_list_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_mentor> list_mentor{};
	public:
		std::vector<mps_mentor> list_mentee{};
	public:
		int64_t mentor_reg_date{};

	public:
		mrpc_gate_mentor_list_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::gate_mentor_list_sc, tag)
		{
		}
		mrpc_gate_mentor_list_sc() : RpcPacket(mpe_rpc_cmd::gate_mentor_list_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &list_mentor);
			protocol::SerializeType(pBuffer, &list_mentee);
			protocol::SerializeType(pBuffer, &mentor_reg_date);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
