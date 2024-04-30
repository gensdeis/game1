#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_siege_warfare_info_for_indun.h"

namespace mir3d
{
	class mrpc_siege_warfare_all_info_for_indun_cs : public RpcPacket 	// 인던 공성전 정보
	{

	public:
		mrpc_siege_warfare_all_info_for_indun_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_all_info_for_indun_cs, tag)
		{
		}
		mrpc_siege_warfare_all_info_for_indun_cs() : RpcPacket(mpe_rpc_cmd::siege_warfare_all_info_for_indun_cs)
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

	class mrpc_siege_warfare_all_info_for_indun_sc : public RpcPacket 	// 인던 공성전 정보
	{
	public:
		std::vector<mrpcs_siege_warfare_info_for_indun> info{};

	public:
		mrpc_siege_warfare_all_info_for_indun_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::siege_warfare_all_info_for_indun_sc, tag)
		{
		}
		mrpc_siege_warfare_all_info_for_indun_sc() : RpcPacket(mpe_rpc_cmd::siege_warfare_all_info_for_indun_sc)
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
