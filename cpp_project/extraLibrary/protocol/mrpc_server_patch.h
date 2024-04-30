#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"

namespace mir3d
{
	class mrpc_server_patch_cs : public RpcPacket 
	{
	public:
		int64_t uid{};
	public:
		int32_t load_index{};

	public:
		mrpc_server_patch_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_patch_cs, tag)
		{
		}
		mrpc_server_patch_cs() : RpcPacket(mpe_rpc_cmd::server_patch_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeType(pBuffer, &load_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_server_patch_sc : public RpcPacket 
	{
	public:
		int64_t uid{};
	public:
		mrpce_service_type type{};
	public:
		int32_t index{};
	public:
		int32_t total_index{};
	public:
		int32_t data_size{};
	public:
		int32_t load_index{};
	public:
		std::vector<uint8_t> data{};

	public:
		mrpc_server_patch_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_patch_sc, tag)
		{
		}
		mrpc_server_patch_sc() : RpcPacket(mpe_rpc_cmd::server_patch_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &uid);
			protocol::SerializeEnum(pBuffer, &type);
			protocol::SerializeType(pBuffer, &index);
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
