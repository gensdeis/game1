#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_table_load_cs : public RpcPacket 
	{
	public:
		int32_t load_index{};

	public:
		mrpc_table_load_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::table_load_cs, tag)
		{
		}
		mrpc_table_load_cs() : RpcPacket(mpe_rpc_cmd::table_load_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &load_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_table_load_sc : public RpcPacket 
	{
	public:
		int64_t uid{};
	public:
		int32_t total_index{};
	public:
		int32_t data_size{};
	public:
		int32_t load_index{};
	public:
		std::vector<uint8_t> data{};

	public:
		mrpc_table_load_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::table_load_sc, tag)
		{
		}
		mrpc_table_load_sc() : RpcPacket(mpe_rpc_cmd::table_load_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &total_index);
			protocol::SerializeType(pBuffer, &data_size);
			protocol::SerializeType(pBuffer, &load_index);
			protocol::SerializeType(pBuffer, &data);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
