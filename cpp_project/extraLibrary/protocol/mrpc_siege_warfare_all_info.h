#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_siege_warfare_info.h"

namespace mir3d
{
	class mrpc_siege_warfare_all_info_cs : public RpcPacket 	// 공성전 정보 요청
	{

	public:
		mrpc_siege_warfare_all_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_all_info_cs, tag)
		{
		}
		mrpc_siege_warfare_all_info_cs() : RpcPacket(mpe_rpc_cmd::siege_warfare_all_info_cs)
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

	class mrpc_siege_warfare_all_info_sc : public RpcPacket 	// 공성전 정보 요청
	{
	public:
		std::vector<mps_siege_warfare_info> info{};	// 공성전 상태

	public:
		mrpc_siege_warfare_all_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_all_info_sc, tag)
		{
		}
		mrpc_siege_warfare_all_info_sc() : RpcPacket(mpe_rpc_cmd::siege_warfare_all_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &info);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
