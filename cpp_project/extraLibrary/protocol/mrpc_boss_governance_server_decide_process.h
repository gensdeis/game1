#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_boss_governance_server_decide_process.h"

namespace mir3d
{
	class mrpc_boss_governance_server_decide_process_cs : public RpcPacket 	// 보스거버넌스 서버결정이후 관련처리
	{

	public:
		mrpc_boss_governance_server_decide_process_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::boss_governance_server_decide_process_cs, tag)
		{
		}
		mrpc_boss_governance_server_decide_process_cs() : RpcPacket(mpe_rpc_cmd::boss_governance_server_decide_process_cs)
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

	class mrpc_boss_governance_server_decide_process_sc : public RpcPacket 	// 보스거버넌스 서버결정이후 관련처리
	{
	public:
		std::vector<mrpcs_boss_governance_server_decide_process> list{};	// 정보 리스트

	public:
		mrpc_boss_governance_server_decide_process_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::boss_governance_server_decide_process_sc, tag)
		{
		}
		mrpc_boss_governance_server_decide_process_sc() : RpcPacket(mpe_rpc_cmd::boss_governance_server_decide_process_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
