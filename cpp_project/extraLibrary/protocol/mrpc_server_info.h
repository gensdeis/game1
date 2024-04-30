#pragma once
#include "base_protocol.h"
#include "rpc_protocol.h"
#include "struct/mrpcs_server_info.h"

namespace mir3d
{
	class mrpc_server_info_cs : public RpcPacket 
	{
	public:
		mrpce_server_type server_type{};
	public:
		int32_t server_index{};

	public:
		mrpc_server_info_cs(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_info_cs, tag)
		{
		}
		mrpc_server_info_cs() : RpcPacket(mpe_rpc_cmd::server_info_cs)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeEnum(pBuffer, &server_type);
			protocol::SerializeType(pBuffer, &server_index);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

	class mrpc_server_info_sc : public RpcPacket 
	{
	public:
		std::vector<mrpcs_server_info> server_info_list{};

	public:
		mrpc_server_info_sc(uint8_t tag) : RpcPacket(mpe_rpc_cmd::server_info_sc, tag)
		{
		}
		mrpc_server_info_sc() : RpcPacket(mpe_rpc_cmd::server_info_sc)
		{
		}

	public:
		template<typename T_BUFFER> void Serialize(T_BUFFER* pBuffer)
		{
			RpcPacket::Serialize(pBuffer);
			protocol::SerializeType(pBuffer, &server_info_list);
		}

		template<typename T_BUFFER> void SerializeEnd(T_BUFFER* pBuffer, int16_t length)
		{
			RpcPacket::SerializeEnd(pBuffer, length);
		}
	};

}
