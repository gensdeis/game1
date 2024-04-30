#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mps_db_buff.h"

namespace mir3d
{
	class mrpc_buff_select_cs : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		int64_t cuid{};

	public:
		mrpc_buff_select_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::buff_select_cs, tag)
		{
		}
		mrpc_buff_select_cs() : RpcPacket(mpe_rpc_cmd::buff_select_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &cuid);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_buff_select_sc : public RpcPacket 
	{
	public:
		int64_t key{};
	public:
		std::vector<mps_db_buff> buffs{};

	public:
		mrpc_buff_select_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::buff_select_sc, tag)
		{
		}
		mrpc_buff_select_sc() : RpcPacket(mpe_rpc_cmd::buff_select_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &key);
			protocol::SerializeType(pBuffer, &buffs);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
